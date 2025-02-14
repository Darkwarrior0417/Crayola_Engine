#pragma once
#include "Prerequisites.h"

/**
 * @class BaseApp
 * @brief Clase base para la aplicación principal.
 *
 * Gestiona la inicialización, actualización, renderización y destrucción de la aplicación.
 */
class BaseApp {
public:
    /**
     * @brief Constructor por defecto.
     *
     * Inicializa una nueva instancia de la clase BaseApp.
     */
    BaseApp() = default;

    /**
     * @brief Destructor por defecto.
     *
     * Libera los recursos de la clase BaseApp al destruir la instancia.
     */
    ~BaseApp() = default;

    /**
     * @brief Inicializa la aplicación.
     *
     * Configura los parámetros iniciales y recursos necesarios para la ejecución de la aplicación.
     *
     * @return HRESULT Indicando el éxito o fallo de la inicialización.
     */
    HRESULT init();

    /**
     * @brief Actualiza la lógica de la aplicación en cada frame.
     *
     * Realiza las actualizaciones necesarias en cada ciclo de la aplicación, como el manejo de eventos y estados.
     */
    void update();

    /**
     * @brief Renderiza el contenido gráfico de la aplicación.
     *
     * Dibuja los elementos visuales de la aplicación en la pantalla.
     */
    void render();

    /**
     * @brief Libera los recursos utilizados por la aplicación.
     *
     * Realiza las tareas de limpieza necesarias para liberar memoria y otros recursos.
     */
    void destroy();

    /**
     * @brief Ejecuta la aplicación.
     *
     * Inicia el ciclo principal de la aplicación, gestionando el ciclo de vida de la ventana y el procesamiento de eventos.
     *
     * @param hInstance Instancia de la aplicación.
     * @param hPrevInstance Instancia previa de la aplicación (normalmente nula en Windows modernos).
     * @param lpCmdLine Línea de comandos pasada a la aplicación.
     * @param nCmdShow Parámetro para mostrar la ventana.
     * @param wndproc Procedimiento de la ventana.
     * @return int Código de retorno de la ejecución.
     */
    int run(HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPWSTR lpCmdLine,
        int nCmdShow,
        WNDPROC wndproc);

private:
    // Variables privadas de la clase (a definir según necesidades).
};
