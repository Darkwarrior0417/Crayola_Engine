#pragma once
#include "Prerequisites.h"
#include "MeshComponent.h"
#include "fbxsdk.h"

/**
 * @brief Estructura auxiliar para representar los datos de un modelo OBJ cargado manualmente.
 */
struct LoadDataOBJ {
	std::string name;
	std::vector<SimpleVertex> vertex;
	std::vector<unsigned int> index;
	int numVertex = 0;
	int numIndex = 0;
};

/**
 * @brief Clase encargada de cargar modelos 3D en formatos FBX y OBJ,
 * procesando su geometría y materiales.
 */
class 
ModelLoader {
public:
	/**
	 * @brief Constructor por defecto.
	 */
	ModelLoader() = default;

	/**
	 * @brief Destructor por defecto.
	 */
	~ModelLoader() = default;

	/**
	 * @brief Inicializa el manejador de FBX SDK.
	 * @return true si la inicialización fue exitosa, false en caso contrario.
	 */
	bool InitializeFBXManager();

	/**
	 * @brief Carga un modelo FBX y procesa sus datos.
	 * @param filepath Ruta del archivo FBX a cargar.
	 * @return true si la carga fue exitosa, false en caso contrario.
	 */
	bool LoadFBX_model(const std::string& filenpath);

	/**
	 * @brief Procesa un nodo del árbol de la escena FBX.
	 * @param node Nodo de la escena a procesar.
	 */
	void ProcessFBXNode(FbxNode* node);

	/**
	* @brief Procesa una malla asociada a un nodo FBX.
	* @param node Nodo que contiene la malla.
	*/
	void ProcessFBXMesh(FbxNode* node);

	/**
	 * @brief Procesa los materiales asociados a una malla FBX.
	 * @param material Material a procesar.
	 */
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
