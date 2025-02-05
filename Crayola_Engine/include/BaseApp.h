#pragma once
#include "Prerequisites.h"

class
	BaseApp {
public:
	BaseApp() = default;
	~BaseApp() = default;

	/**
	 * @brief Inicializa la aplicaci�n.
	 *
	 * @return HRESULT Indica el �xito o fallo de la operaci�n.
	 */
	HRESULT
		init();

	/**
	 * @brief Actualiza el estado de la aplicaci�n.
	 */
	void
		update();

	/**
	 * @brief Renderiza el contenido de la aplicaci�n.
	 */
	void
		render();

	/**
	 * @brief Destruye la aplicaci�n y libera los recursos asociados.
	 */
	void
		destroy();

	/**
	 * @brief Ejecuta la aplicaci�n.
	 *
	 * @param hInstance Instancia del m�dulo de la aplicaci�n.
	 * @param hPrevInstance Instancia previa del m�dulo de la aplicaci�n.
	 * @param lpCmdLine Puntero a la l�nea de comandos.
	 * @param nCmdShow Especifica c�mo se debe mostrar la ventana.
	 * @param wndproc Funci�n de procedimiento de ventana.
	 * @return int Indica el �xito o fallo de la operaci�n.
	 */
	int
		run(HINSTANCE hInstance,
			HINSTANCE hPrevInstance,
			LPWSTR lpCmdLine,
			int nCmdShow,
			WNDPROC wndproc);

private:

};