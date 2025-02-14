#pragma once

// Librerías estándar
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>
#include <xnamath.h>
//#include <memory>
#include <thread>

// Librerías DirectX
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include "Resource.h"
#include "resource.h"

/**
 * Macro para liberar recursos de DirectX de forma segura.
 * Evita fugas de memoria al asegurarse de liberar los recursos antes de establecerlos en nullptr.
 */
#define SAFE_RELEASE(x) if(x != nullptr) x->Release(); x = nullptr;

 /**
  * Macro para imprimir mensajes de depuración sobre la creación de recursos.
  *
  * @param classObj Nombre de la clase que llama.
  * @param method Nombre del método donde se ejecuta.
  * @param state Estado de la creación del recurso.
  */
#define MESSAGE( classObj, method, state )   \
{                                            \
   std::wostringstream os_;                  \
   os_ << classObj << "::" << method << " : " << "[CREACIÓN DE RECURSO " << ": " << state << "] \n"; \
   OutputDebugStringW( os_.str().c_str() );  \
}

  /**
   * Macro para registrar errores en la depuración y terminar la ejecución.
   *
   * @param classObj Nombre de la clase donde ocurrió el error.
   * @param method Método en el que ocurrió el error.
   * @param errorMSG Mensaje descriptivo del error.
   */
#define ERROR( classObj, method, errorMSG )  \
{                                            \
   std::wostringstream os_;                  \
   os_ << "ERROR : " << classObj << "::" << method << " : " << "  Error en los datos de los parámetros [" << errorMSG << "] \n"; \
   OutputDebugStringW( os_.str().c_str() );  \
   exit(1);                                  \
}

   /**
    * Estructura que define un vértice simple con posición y coordenadas de textura.
    */
struct
    SimpleVertex {
    XMFLOAT3 Pos;  ///< Posición del vértice en el espacio 3D.
    XMFLOAT2 Tex;  ///< Coordenadas de textura del vértice.
};

/**
 * Estructura para almacenar la matriz de vista utilizada en la renderización.
 */
struct
    CBNeverChanges {
    XMMATRIX mView;  ///< Matriz de vista utilizada para transformar los objetos en el mundo.
};

/**
 * Estructura para almacenar la matriz de proyección que cambia al redimensionar la ventana.
 */
struct
    CBChangeOnResize {
    XMMATRIX mProjection;  ///< Matriz de proyección para gestionar la perspectiva de la escena.
};

/**
 * Estructura que almacena transformaciones y color del objeto a ser renderizado.
 */
struct
    CBChangesEveryFrame {
    XMMATRIX mWorld;      ///< Matriz de transformación del mundo para cada frame.
    XMFLOAT4 vMeshColor;  ///< Color del objeto en RGBA.
};

/**
 * Enumeración para definir los tipos de extensiones de imagen soportadas.
 */
enum
    ExtensionType {
    DDS = 0, ///< Imagen en formato DDS (DirectDraw Surface).
    PNG = 1, ///< Imagen en formato PNG.
    JPG = 2  ///< Imagen en formato JPG.
};