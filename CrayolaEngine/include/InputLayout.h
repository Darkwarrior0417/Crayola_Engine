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