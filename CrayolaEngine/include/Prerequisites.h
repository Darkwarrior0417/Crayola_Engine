#pragma once

// ─────────────────────────────────────────────
// Librerías estándar (STD)
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>
#include <xnamath.h>
#include <thread> // Para funcionalidades con múltiples hilos

// ─────────────────────────────────────────────
// Librerías de DirectX
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include "Resource.h"
#include "resource.h"

// ─────────────────────────────────────────────
// Librerías ImGui (interfaz gráfica)
#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_internal.h>
#include "imgui_impl_win32.h"

// Third parties
#include "utilities/Memory/TSharedPointer.h"
#include "utilities/Memory/TWeakPointer.h"
#include "utilities/Memory/TStaticPtr.h"
#include "utilities/Memory/TUniquePtr.h"

// ─────────────────────────────────────────────
// Macros útiles

// Libera memoria y pone el puntero en nullptr
#define SAFE_RELEASE(x) if(x != nullptr) x->Release(); x = nullptr;

// Mensaje informativo de creación de recursos
#define MESSAGE(classObj, method, state)                       \
{                                                              \
   std::wostringstream os_;                                    \
   os_ << classObj << "::" << method << " : "                  \
       << "[CREATION OF RESOURCE : " << state << "] \n";       \
   OutputDebugStringW(os_.str().c_str());                      \
}

// Macro para mostrar errores con contexto
#define ERROR(classObj, method, errorMSG)                      \
{                                                              \
    try {                                                      \
        std::wostringstream os_;                               \
        os_ << L"ERROR : " << classObj << L"::" << method      \
            << L" : " << errorMSG << L"\n";                    \
        OutputDebugStringW(os_.str().c_str());                 \
    } catch (...) {                                            \
        OutputDebugStringW(L"Not Loaded correctly");           \
    }                                                          \
}

// ─────────────────────────────────────────────
// Estructuras

// Vértice simple: posición y coordenada de textura
struct SimpleVertex {
    XMFLOAT3 Pos;
    XMFLOAT2 Tex;
};

// Buffer constante que nunca cambia (ej. vista)
struct CBNeverChanges {
    XMMATRIX mView;
};

// Buffer que cambia cuando se redimensiona la ventana
struct CBChangeOnResize {
    XMMATRIX mProjection;
};

// Buffer que cambia cada frame (mundo y color)
struct CBChangesEveryFrame {
    XMMATRIX mWorld;
    XMFLOAT4 vMeshColor;
};

// ─────────────────────────────────────────────
// Enumeraciones

// Tipos de extensión de imagen
enum ExtensionType {
    DDS = 0,
    PNG = 1,
    JPG = 2
};

// Tipos de shader utilizados
enum ShaderType {
    VERTEX_SHADER = 0,
    PIXEL_SHADER = 1
};

// Tipos de componentes dentro del sistema (entidades)
enum ComponentType {
    NONE = 0,      // No definido
    TRANSFORM = 1, // Posición, rotación, escala
    MESH = 2,      // Malla 3D
    MATERIAL = 3   // Material o textura
};

// ─────────────────────────────────────────────
// Cámara con orientación en espacio 3D
struct Camera {
    XMFLOAT3 position;  // Posición de la cámara
    XMFLOAT3 target;    // Hacia dónde está mirando
    XMFLOAT3 up;        // Vector hacia arriba
    XMFLOAT3 forward;   // Dirección hacia el frente
    XMFLOAT3 right;     // Dirección hacia la derecha

    float yaw;          // Rotación horizontal (Y)
    float pitch;        // Rotación vertical (X)

    // Constructor con valores iniciales
    Camera() {
        position = XMFLOAT3(0.0f, 1.0f, -5.0f);
        target = XMFLOAT3(0.0f, 1.0f, 0.0f);
        up = XMFLOAT3(0.0f, 1.0f, 0.0f);
        forward = XMFLOAT3(0.0f, 0.0f, 1.0f);
        right = XMFLOAT3(1.0f, 0.0f, 0.0f);
        yaw = 0.0f;
        pitch = 0.0f;
    }
};
