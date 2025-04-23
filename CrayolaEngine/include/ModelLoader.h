#pragma once
#include "Prerequisites.h"
#include "MeshComponent.h"
#include "fbxsdk.h"

// Estructura auxiliar para representar datos crudos de un modelo OBJ
struct LoadDataOBJ {
	std::string name;
	std::vector<SimpleVertex> vertex;
	std::vector<unsigned int> index;
	int numVertex = 0;
	int numIndex = 0;
};

class ModelLoader {
public:
	ModelLoader() = default;
	~ModelLoader() = default;

	// Inicializa el manejador FBX
	bool InitializeFBXManager();

	// Carga modelo FBX
	bool LoadFBX_model(const std::string& filenpath);

	// Procesa nodos y mallas FBX
	void ProcessFBXNode(FbxNode* node);
	void ProcessFBXMesh(FbxNode* node);
	void ProcessFBXMaterials(FbxSurfaceMaterial* material);

	// Obtiene nombres de texturas de materiales FBX
	std::vector<std::string> GetTextureFileNames() const { return textureFileNames; };

	// Carga modelo OBJ en m_meshes directamente
	bool LoadOBJ_model(const std::string& filePath);

	// Alternativa: carga modelo OBJ y devuelve los datos crudos
	LoadDataOBJ LoadOBJ(std::string objFileName);

public:
	// Meshes procesadas del modelo (FBX u OBJ)
	std::vector<MeshComponent> m_meshes;

private:
	// Internos del SDK FBX
	FbxManager* lSdkManager = nullptr;
	FbxScene* lScene = nullptr;
	std::vector<std::string> textureFileNames;
};
