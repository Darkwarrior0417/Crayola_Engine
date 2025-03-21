#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;

// Encapsula la creación y manejo de un Sampler State en DirectX 11.
class SamplerState {
public:
    SamplerState() = default;
    ~SamplerState() = default;

    // Inicializa el sampler con configuración por defecto.
    HRESULT init(Device& device);

    // Actualiza el estado interno del sampler (si aplica).
    void update();

    // Establece el sampler en el pipeline de renderizado.
    void render(DeviceContext& deviceContext,
        unsigned int StartSlot,
        unsigned int NumSamplers);

    // Libera los recursos del sampler.
    void destroy();

public:
    ID3D11SamplerState* m_sampler = nullptr; // Puntero al sampler de DirectX 11.
};
