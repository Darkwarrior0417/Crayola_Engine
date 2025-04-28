CrayolaEngine

CrayolaEngine es un motor de videojuegos desarrollado en C++ como parte del proyecto universitario del 8vo cuatrimestre de la carrera. Diseñado con una arquitectura modular, escalable y optimizada, este motor sirve como base educativa para comprender los fundamentos internos de los motores gráficos modernos y ser todos unos pros.

🚀 Tecnologías Utilizadas

Lenguaje: C++

Entorno de Desarrollo: Microsoft Visual Studio

Gráficos: DirectX 11

UI: ImGui (Docking + Ventanas Custom)

🎯 Objetivo del Proyecto

Este motor fue creado con el propósito de entender, analizar y aplicar los principios de arquitectura de motores de videojuegos. A través de su estructura modular y componentes esenciales, permite explorar desde la gestión de recursos, el ciclo de renderizado y el uso de shaders, hasta la integración de interfaces gráficas en tiempo real.

📚 Avance Parcial por Entrega

PRIMER PARCIAL

Window.h — Inicializa y configura la ventana principal (Win32 API).

Device.h — Crea y administra el dispositivo Direct3D.

DeviceContext.h — Encargado de emitir comandos de render a la GPU.

Texture.h — Carga texturas desde archivos DDS y PNG (usa stb_image para PNG).

SwapChain.h — Gestiona los buffers para presentar la imagen en pantalla.

RenderTargetView.h — Configura la vista del render target.

DepthStencilView.h — Maneja la profundidad para el orden de dibujo de objetos.

SEGUNDO PARCIAL

Viewport.h — Define el área de visualización del render.

InputLayout.h — Establece el formato de los vértices enviados al pipeline.

ShaderProgram.h — Maneja la carga, compilación y uso de shaders.

Buffer.h — Administra los Vertex, Index y Constant Buffers.

SamplerState.h — Controla el muestreo de texturas.

UI.h (UserInterface) — Implementa una interfaz de usuario gráfica utilizando ImGui (Docking + Custom Windows).
![image](https://github.com/user-attachments/assets/24d57cb6-e5d7-4ffd-a43f-bac4a2f6953c)


TERCER PARCIAL

ModelLoader.h / ModelLoader.cpp — Carga modelos 3D en formato .fbx utilizando FBX SDK y .obj utilizando un parser propio basado en OBJ_Loader.h.

MultiMesh y MultiTexture Support — Se integró la carga de múltiples sub-mallas y su asignación correcta de texturas individuales.

Actor.h / Actor.cpp — Nueva estructura para representar objetos de juego (Actors) con componentes de Transform y MeshComponent, soportando jerarquía y transformación completa (posición, rotación, escala).

Transform.h / Transform.cpp — Componente que administra la transformación espacial de los actores.

Jerarquía e Inspector en ImGui — Implementado un sistema donde se pueden ver los actores en una jerarquía de escena, seleccionar y modificar su posición, rotación y escala en tiempo real.

Soporte a Carga de Materiales Básicos desde OBJ/FBX — Se obtiene automáticamente la textura difusa (Diffuse) de los modelos cargados.

Mejoras en la gestión de recursos — Limpieza automática de Buffers, Texturas y Samplers al destruir los actores.

Actualmente estos añadidos a la solución le dan la capacidad al motor para cargar y representar modelos 3D complejos provenientes de formatos OBJ y FBX, incluyendo la gestión de submeshes y aplicación de texturas específicas por material. Se mejoró la jerarquía de actores evitando duplicaciones de componentes y permitiendo un control claro y organizado de la escena.

![image](https://github.com/user-attachments/assets/af838825-0c0c-4934-9ea9-99875d3a6095)


