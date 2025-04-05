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
	// Inicializa el administrador de FBX
	if (InitializeFBXManager()) {
		// Crea un importador usando el administrador del SDK
		FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");

		// Usa la ruta del archivo como entrada del importador
		if (!lImporter->Initialize(filePath.c_str(), -1, lSdkManager->GetIOSettings())) {
			ERROR("ModelLoader", "LoadFBXModel", "No se pudo inicializar el importador FBX para el archivo: " << filePath.c_str());
			ERROR("ModelLoader", "LoadFBXModel", "Error devuelto: " << lImporter->GetStatus().GetErrorString());
			return false;
		}

		// Importa la escena
		if (!lImporter->Import(lScene)) {
			ERROR("ModelLoader", "lImporter->Import", "No se pudo importar la escena FBX desde el archivo: " << filePath.c_str());
			lImporter->Destroy();
			return false;
		}

		// Destruye el importador
		lImporter->Destroy();
		MESSAGE("ModelLoader", "LoadFBXModel", "Escena FBX importada exitosamente desde: " << filePath.c_str());

		// Procesa la escena
		FbxNode* lRootNode = lScene->GetRootNode();

		if (lRootNode) {
			for (int i = 0; i < lRootNode->GetChildCount(); i++) {
				ProcessFBXNode(lRootNode->GetChild(i));
			}
		}

		// Procesa los materiales
		int materialCount = lScene->GetMaterialCount();
		for (int i = 0; i < materialCount; i++) {
			FbxSurfaceMaterial* material = lScene->GetMaterial(i);
			ProcessFBXMaterials(material);
		}
	}
	else {
		ERROR("ModelLoader", "LoadFBXModel", "Fallo al inicializar el administrador de FBX.");
		return false;
	}
	return false;
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

void
ModelLoader::ProcessFBXMesh(FbxNode* node) {
	// Obtiene el mesh del nodo. Si no hay mesh, sale de la función.
	FbxMesh* mesh = node->GetMesh();
	if (!mesh) return;

	std::vector<SimpleVertex> vertices;
	std::vector<unsigned int> indices;

	// Procesa vértices: extrae posiciones desde los puntos de control.
	for (int i = 0; i < mesh->GetControlPointsCount(); i++) {
		SimpleVertex vertex;
		FbxVector4* controlPoint = mesh->GetControlPoints();
		vertex.Pos = XMFLOAT3((float)controlPoint[i][0],
			(float)controlPoint[i][1],
			(float)controlPoint[i][2]);
		vertices.push_back(vertex);
	}

	// Procesa coordenadas UV si están disponibles.
	if (mesh->GetElementUVCount() > 0) {
		FbxGeometryElementUV* uvElement = mesh->GetElementUV(0);
		FbxGeometryElement::EMappingMode mappingMode = uvElement->GetMappingMode();
		FbxGeometryElement::EReferenceMode referenceMode = uvElement->GetReferenceMode();
		int polyIndexCounter = 0; // Contador para índices de vértices de polígonos.

		// Itera por cada polígono del mesh.
		for (int polyIndex = 0; polyIndex < mesh->GetPolygonCount(); polyIndex++) {
			int polySize = mesh->GetPolygonSize(polyIndex);

			// Procesa cada vértice del polígono.
			for (int vertIndex = 0; vertIndex < polySize; vertIndex++) {
				int controlPointIndex = mesh->GetPolygonVertex(polyIndex, vertIndex);
				int uvIndex = -1;

				// Mapeo UV por punto de control
				if (mappingMode == FbxGeometryElement::eByControlPoint) {
					if (referenceMode == FbxGeometryElement::eDirect) {
						uvIndex = controlPointIndex;
					}
					else if (referenceMode == FbxGeometryElement::eIndexToDirect) {
						uvIndex = uvElement->GetIndexArray().GetAt(controlPointIndex);
					}
				}
				// Mapeo UV por vértice de polígono
				else if (mappingMode == FbxGeometryElement::eByPolygonVertex) {
					if (referenceMode == FbxGeometryElement::eDirect || referenceMode == FbxGeometryElement::eIndexToDirect) {
						uvIndex = uvElement->GetIndexArray().GetAt(polyIndexCounter);
						polyIndexCounter++;
					}
				}

				// Si se encuentra un índice UV válido, se asigna la coordenada de textura.
				if (uvIndex != -1) {
					FbxVector2 uv = uvElement->GetDirectArray().GetAt(uvIndex);
					vertices[controlPointIndex].Tex = XMFLOAT2((float)uv[0], -(float)uv[1]);
				}
			}
		}
	}

	// Procesa índices: almacena cada índice de vértice del polígono.
	for (int i = 0; i < mesh->GetPolygonCount(); i++) {
		for (int j = 0; j < mesh->GetPolygonSize(i); j++) {
			indices.push_back(mesh->GetPolygonVertex(i, j));
		}
	}

	// Crea un MeshComponent para guardar los datos procesados del mesh.
	MeshComponent meshData;
	meshData.m_name = node->GetName();
	meshData.m_vertex = vertices;
	meshData.m_index = indices;
	meshData.m_numVertex = vertices.size();
	meshData.m_numIndex = indices.size();

	// Agrega los datos procesados a la colección.
	m_meshes.push_back(meshData);
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