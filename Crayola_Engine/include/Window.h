#pragma once
#include "Prerequisites.h"

class
Window {
public:
	/**
	 * @brief Constructor y destructor por defecto.
	 */
	Window() = default;
	~Window() = default;

	/**
	 * @brief Inicializa la ventana.
	 * 
	 * @param hInstance Instancia de la aplicación.
	 * @param nCmdShow Comando para mostrar la ventana.
	 * @param wndproc Procedimiento de ventana (callback).
	 * @return HRESULT Resultado de la inicialización.
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
	// Instancia de la aplicación.
	HINSTANCE m_hInst = nullptr;
	// Estructura que define el tamaño de la ventana.
	RECT m_rect;
	// Nombre de la ventana.
	std::string m_windowName = "Crayola_Engine";
};
