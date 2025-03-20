#pragma once
#include "Prerequisites.h"

class Window;


class UI {

public:
    UI() = default;
    ~UI() = default;

    void
        init(void* window, ID3D11Device* device, ID3D11DeviceContext* deviceContext);

    void
        update();

    void
        render();

    void
        destroy();

    void
        baseStyleGUI();

    void
        renderWindow();

    void
        Inspector();

    void
        vec3Control(std::string label,
            float* value,
            float resetValues = 0.0f,
            float columnWidth = 100.0f);
};