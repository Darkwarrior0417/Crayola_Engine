#pragma once
#include "Prerequisites.h"

// Declaraciones adelantadas para evitar inclusiones circulares
class Device;
class DeviceContext;

/**
 * @brief Clase que encapsula la creación, configuración y uso de un Sampler State en DirectX 11.
 * Un Sampler define cómo se muestrean las texturas (filtros, direccionamiento, etc.).
 */
class 
SamplerState {
public:
    /**
     * @brief Constructor por defecto.
     */
    SamplerState() = default;

    /**
    * @brief Destructor por defecto.
    */
    ~SamplerState() = default;

    // Inicializa el sampler con configuración por defecto.
    HRESULT 
    init(Device& device);

    /**
     * @brief Actualiza el estado interno del Sampler (no utilizado normalmente).
     */
    void 
    update();

    // Establece el sampler en el pipeline de renderizado.
    void 
    render(DeviceContext& deviceContext,
        unsigned int StartSlot,
        unsigned int NumSamplers);

    /**
     * @brief Libera los recursos asociados al Sampler State.
     */
    void 
    destroy();

public:
    ID3D11SamplerState* m_sampler = nullptr; // Puntero al sampler de DirectX 11.
};
