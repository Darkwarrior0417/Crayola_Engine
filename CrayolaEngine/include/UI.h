#pragma once
#include "Prerequisites.h"

class Window;

/**
 * @brief Encapsula el sistema de interfaz gr�fica (UI) usando ImGui.
 */
class UI {
public:
    UI() = default;
    ~UI() = default;

    /**
     * @brief Inicializa ImGui con la ventana y los dispositivos de DirectX.
     * @param window Puntero a la ventana Win32.
     * @param device Dispositivo DirectX 11.
     * @param deviceContext Contexto del dispositivo.
     */
    void init(void* window, ID3D11Device* device, ID3D11DeviceContext* deviceContext);

    /**
     * @brief Actualiza la l�gica interna de la UI por frame.
     */
    void update();

    /**
     * @brief Renderiza todos los elementos visuales de la UI.
     */
    void render();

    /**
     * @brief Libera los recursos utilizados por ImGui.
     */
    void destroy();

    /**
     * @brief Aplica un estilo base personalizado a la interfaz.
     */
    void baseStyleGUI();

    /**
     * @brief Renderiza la ventana principal del sistema UI.
     */
    void renderWindow();

    /**
     * @brief Muestra el panel "Inspector" para ver/editar propiedades.
     */
    void Inspector();

    /**
     * @brief Control tipo vec3 interactivo con sliders y bot�n de reset.
     * @param label Etiqueta del control.
     * @param value Puntero al array de 3 floats (x, y, z).
     * @param resetValues Valor al que se reinicia cada componente.
     * @param columnWidth Ancho de la primera columna del layout.
     */
    void vec3Control(std::string label,
        float* value,
        float resetValues = 0.0f,
        float columnWidth = 100.0f);
};
