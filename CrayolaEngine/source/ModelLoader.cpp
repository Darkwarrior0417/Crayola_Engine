#include "ModelLoader.h"

bool
ModelLoader::InitializeFBXManager() {
	// Inicializa el administrador del SDK. Este objeto gestiona toda la memoria.
	lSdkManager = FbxManager::Create();
	if (!lSdkManager) {
		ERROR("ModelLoader", "InitializeFBXManager", "No se pudo crear el administrador del SDK de FBX.");
		return false;
	}
	else {
		MESSAGE("ModelLoader", "InitializeFBXManager", "Administrador del SDK de FBX creado exitosamente." << lSdkManager->GetVersion());
	}

	// Crea un objeto IOSettings. Este objeto contiene toda la configuración de importación/exportación.
	FbxIOSettings* ios = FbxIOSettings::Create(lSdkManager, IOSROOT);
	lSdkManager->SetIOSettings(ios);

	// Crea una escena FBX. Esta contiene la mayoría de los objetos importados/exportados.
	lScene = FbxScene::Create(lSdkManager, "Mi Escena ");
	return true;
}

bool
ModelLoader::LoadFBX_model(const std::string& filePath) {
	OutputDebugStringA("Iniciando carga del modelo FBX...\n");

	if (InitializeFBXManager()) {
		OutputDebugStringA(" FBX Manager inicializado correctamente.\n");

		FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");

		if (!lImporter->Initialize(filePath.c_str(), -1, lSdkManager->GetIOSettings())) {
			OutputDebugStringA(" Error en Initialize del FBX Importer.\n");
			OutputDebugStringA(lImporter->GetStatus().GetErrorString());
			ERROR("ModelLoader", "LoadFBXModel", "No se pudo inicializar el importador FBX para el archivo: " << filePath.c_str());
			lImporter->Destroy();
			return false;
		}

		OutputDebugStringA(" FBX Importer inicializado.\n");

		if (!lImporter->Import(lScene)) {
			OutputDebugStringA(" Error al importar la escena FBX.\n");
			ERROR("ModelLoader", "lImporter->Import", "No se pudo importar la escena FBX desde el archivo: " << filePath.c_str());
			lImporter->Destroy();
			return false;
		}

		OutputDebugStringA(" Escena FBX importada.\n");
		lImporter->Destroy();

		FbxNode* lRootNode = lScene->GetRootNode();
		if (lRootNode) {
			OutputDebugStringA(" Procesando nodos de la escena...\n");
			for (int i = 0; i < lRootNode->GetChildCount(); i++) {
				ProcessFBXNode(lRootNode->GetChild(i));
			}
		}

		int materialCount = lScene->GetMaterialCount();
		OutputDebugStringA(" Procesando materiales...\n");
		for (int i = 0; i < materialCount; i++) {
			FbxSurfaceMaterial* material = lScene->GetMaterial(i);
			ProcessFBXMaterials(material);
		}

		OutputDebugStringA(" Modelo FBX cargado exitosamente.\n");
		return true;
	}
	else {
		OutputDebugStringA(" No se pudo inicializar el FBX Manager.\n");
		ERROR("ModelLoader", "LoadFBXModel", "Fallo al inicializar el administrador de FBX.");
		return false;
	}
}

void
ModelLoader::ProcessFBXNode(FbxNode* node) {
	// Procesa todos los meshes del nodo
	if (node->GetNodeAttribute()) {
		if (node->GetNodeAttribute()->GetAttributeType() == FbxNodeAttribute::eMesh) {
			ProcessFBXMesh(node);
		}
	}

	// Procesa recursivamente los nodos hijos
	for (int i = 0; i < node->GetChildCount(); i++) {
		ProcessFBXNode(node->GetChild(i));
	}
}

void ModelLoader::ProcessFBXMesh(FbxNode* node) {
	FbxMesh* mesh = node->GetMesh();
	if (!mesh) return;

	std::vector<std::pair<int, std::vector<SimpleVertex>>> materialToVertices;
	std::vector<std::pair<int, std::vector<unsigned int>>> materialToIndices;

	FbxGeometryElementUV* uvElement = mesh->GetElementUV(0);
	FbxGeometryElementMaterial* matElement = mesh->GetElementMaterial();

	int polyCounter = 0;

	for (int polyIndex = 0; polyIndex < mesh->GetPolygonCount(); ++polyIndex) {
		int materialIndex = 0;
		if (matElement && matElement->GetMappingMode() == FbxGeometryElement::eByPolygon) {
			materialIndex = matElement->GetIndexArray().GetAt(polyIndex);
		}

		// Buscar si ya hay una entrada para este material
		size_t matPos = 0;
		bool found = false;
		for (; matPos < materialToVertices.size(); ++matPos) {
			if (materialToVertices[matPos].first == materialIndex) {
				found = true;
				break;
			}
		}
		if (!found) {
			materialToVertices.push_back({ materialIndex, {} });
			materialToIndices.push_back({ materialIndex, {} });
			matPos = materialToVertices.size() - 1;
		}

		for (int vertIndex = 0; vertIndex < mesh->GetPolygonSize(polyIndex); ++vertIndex) {
			int ctrlPointIndex = mesh->GetPolygonVertex(polyIndex, vertIndex);

			FbxVector4 pos = mesh->GetControlPointAt(ctrlPointIndex);
			SimpleVertex vertex;
			vertex.Pos = XMFLOAT3((float)pos[0], (float)pos[1], (float)pos[2]);

			if (uvElement && uvElement->GetMappingMode() == FbxGeometryElement::eByPolygonVertex) {
				int uvIndex = uvElement->GetIndexArray().GetAt(polyCounter);
				FbxVector2 uv = uvElement->GetDirectArray().GetAt(uvIndex);
				vertex.Tex = XMFLOAT2((float)uv[0], -(float)uv[1]);
			}

			materialToVertices[matPos].second.push_back(vertex);
			materialToIndices[matPos].second.push_back((unsigned int)(materialToVertices[matPos].second.size() - 1));

			polyCounter++;
		}
	}

	// Convertir cada par en un submesh
	for (size_t i = 0; i < materialToVertices.size(); ++i) {
		MeshComponent meshData;
		meshData.m_name = node->GetName() + std::string("_material_") + std::to_string(materialToVertices[i].first);
		meshData.m_vertex = materialToVertices[i].second;
		meshData.m_index = materialToIndices[i].second;
		meshData.m_numVertex = (unsigned int)meshData.m_vertex.size();
		meshData.m_numIndex = (unsigned int)meshData.m_index.size();

		m_meshes.push_back(meshData);
		MESSAGE("ModelLoader", "Submesh", ("Submesh creado: " + meshData.m_name).c_str());
	}
}
void
ModelLoader::ProcessFBXMaterials(FbxSurfaceMaterial* material) {
	if (material) {
		FbxProperty prop = material->FindProperty(FbxSurfaceMaterial::sDiffuse);
		if (prop.IsValid()) {
			int textureCount = prop.GetSrcObjectCount<FbxTexture>();
			for (int i = 0; i < textureCount; i++) {
				FbxTexture* texture = FbxCast<FbxTexture>(prop.GetSrcObject<FbxTexture>(i));
				if (texture) {
					textureFileNames.push_back(texture->GetName());
				}
			}
		}
	}
}