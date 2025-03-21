# CrayolaEngine
CrayolaEngine es un motor de videojuegos desarrollado en C++ como parte del proyecto de uni del 8vo cuatrimestre de la carrera. Diseñado con una arquitectura modular, escalable y optimizada, este motor sirve como base educativa para comprender los fundamentos internos de los motores gráficos modernos y ser todos unos pros.

🚀 Tecnologías Utilizadas

Lenguaje: C++

Entorno de Desarrollo: Microsoft Visual Studio 

Gráficos: DirectX 11

UI: ImGui (Docking + Ventanas Custom)

🎯 Objetivo del Proyecto

Este motor fue creado con el propósito de entender, analizar y aplicar los principios de arquitectura de motores de videojuegos. A través de su estructura modular y componentes esenciales, permite explorar desde la gestión de recursos, el ciclo de renderizado y el uso de shaders, hasta la integración de interfaces gráficas en tiempo real.

Primer Parcial

Window.h — Inicializa y configura la ventana principal (Win32 API).

Device.h — Crea y administra el dispositivo Direct3D.

DeviceContext.h — Encargado de emitir comandos de render a la GPU.

Texture.h — Carga texturas desde archivos DDS y PNG (usa stb_image para PNG).

SwapChain.h — Gestiona los buffers para presentar la imagen en pantalla.

RenderTargetView.h — Configura la vista del render target.

DepthStencilView.h — Maneja la profundidad para el orden de dibujo de objetos.

Segundo Parcial

Viewport.h — Define el área de visualización del render.

InputLayout.h — Establece el formato de los vértices enviados al pipeline.

ShaderProgram.h — Maneja la carga, compilación y uso de shaders.

Buffer.h — Administra los Vertex, Index y Constant Buffers.

SamplerState.h — Controla el muestreo de texturas.

UI.h (UserInterface) — Implementa una interfaz de usuario con ImGui.


