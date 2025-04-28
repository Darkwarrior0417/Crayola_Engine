#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;

class
InputLayout {
public:

	/* @brief Constructor por defecto. */

	InputLayout() = default;

	/* @brief Destructor por defecto. */

	~InputLayout() = default;

	/**
	* @brief Inicializa el Input Layout a partir de una descripción de los elementos de entrada
	* y los datos compilados del Vertex Shader.
	* @param device Referencia al dispositivo de renderizado.
	* @param Layout Vector que describe el formato de los datos de entrada.
	* @param VertexShaderData Datos compilados del Vertex Shader (bytecode).
	* @return HRESULT que indica éxito o error.
	*/
	HRESULT
	init(Device& device,
			std::vector<D3D11_INPUT_ELEMENT_DESC>& Layout,
			ID3DBlob* VertexShaderData);

	/*
	 * @brief Actualiza el estado interno del input layout.
	 */
	void
	update();

	/*
	 * @brief Establece el input layout en el pipeline gráfico.
	 * @param deviceContext Contexto de dispositivo.
	 */
	void
	render(DeviceContext& deviceContext);

	/*
	 * @brief Libera los recursos asociados al input layout.
	 */
	void
	destroy();

public:
	ID3D11InputLayout* m_inputLayout = nullptr;
};