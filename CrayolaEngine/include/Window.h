#pragma once
#include "Prerequisites.h"

class
Window {
public:
	/**
	 * @brief Constructor por defecto.
	 */
	Window() = default;

	/**
	 * @brief Destructor por defecto.
	 */
	~Window() = default;

	/**
	 * @brief Inicializa la ventana.
	 *
	 * @param hInstance Instancia de la aplicaci�n.
	 * @param nCmdShow Comando para mostrar la ventana.
	 * @param wndproc Procedimiento de ventana (callback).
	 * @return HRESULT Resultado de la inicializaci�n.
	 */
	HRESULT
	init(HINSTANCE hInstance, int nCmdShow, WNDPROC wndproc);

	/**
	 * @brief Actualiza el estado de la ventana.
	 */
	void
	update();

	/**
	 * @brief Renderiza el contenido de la ventana.
	 */
	void
	render();

	/**
	 * @brief Libera los recursos de la ventana.
	 */
	void
	destroy();

public:
	// Handle de la ventana.
	HWND m_hWnd = nullptr;
	// Ancho de la ventana.
	unsigned int m_width;
	// Altura de la ventana.
	unsigned int m_height;

private:
	// Instancia de la aplicaci�n.
	HINSTANCE m_hInst = nullptr;
	// Estructura que define el tama�o de la ventana.
	RECT m_rect;
	// Nombre de la ventana.
	std::string m_windowName = "Crayola_Engine";
};