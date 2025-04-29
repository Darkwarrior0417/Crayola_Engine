#pragma once
#include "Prerequisites.h"
#include "ECS/Transform.h"

class Window;

/**
 * @brief Encapsula el sistema de interfaz gráfica (UI) usando ImGui.
 */
class 
UI {
public:
    /**
     * @brief Constructor por defecto.
     */
    UI() = default;

    /**
     * @brief Destructor por defecto.
     */
    ~UI() = default;

    /**
     * @brief Inicializa ImGui con la ventana y los dispositivos de DirectX.
     * @param window Puntero a la ventana Win32.
     * @param device Dispositivo DirectX 11.
     * @param deviceContext Contexto del dispositivo.
     */
    void 
    init(void* window, ID3D11Device* device, ID3D11DeviceContext* deviceContext);

    /**
     * @brief Actualiza la lógica interna de la UI por frame.
     */
    void 
    update();

    /**
     * @brief Renderiza todos los elementos visuales de la UI.
     */
    void 
    render();

    /**
     * @brief Libera los recursos utilizados por ImGui.
     */
    void 
    destroy();

    /**
     * @brief Aplica un estilo base personalizado a la interfaz.
     */
    void 
    baseStyleGUI();

    /**
     * @brief Genera una interfaz gráfica para modificar una Transformación (posición, rotación, escala).
     */
    void 
    TransformGUI(Transform& transform);

    /**
     * @brief Renderiza la ventana principal del sistema UI.
     */
    void 
    renderWindow();

    /**
     * @brief Muestra el panel "Inspector" para ver/editar propiedades.
     */
    void 
    Inspector();

    /**
    * @brief Muestra una ventana de lista de actores y permite seleccionar uno para edición.
    */
    void 
    ActorSelector();  // Muestra lista de actores y permite seleccionar

    /**
     * @brief Control tipo vec3 interactivo con sliders y botón de reset.
     * @param label Etiqueta del control.
     * @param value Puntero al array de 3 floats (x, y, z).
     * @param resetValues Valor al que se reinicia cada componente.
     * @param columnWidth Ancho de la primera columna del layout.
     */
    void 
    vec3Control(const std::string& label,
        float* values,
        float resetValues = 0.0f,
        float columnWidth = 100.0f);

};
