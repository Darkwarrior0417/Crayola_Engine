#pragma once
// Librerias STD
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>
#include <xnamath.h>

//#include <memory>
#include <thread>

// Librerias DirectX
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include "Resource.h"
#include "resource.h"

// MACROS
#define SAFE_RELEASE(x) if(x != nullptr) x->Release(); x = nullptr;

#define MESSAGE( classObj, method, state )   \
{                                            \
   std::wostringstream os_;                  \
   os_ << classObj << "::" << method << " : " << "[CREATION OF RESOURCE " << ": " << state << "] \n"; \
   OutputDebugStringW( os_.str().c_str() );  \
}

#define ERROR( classObj, method, errorMSG )  \
{                                            \
   std::wostringstream os_;                  \
   os_ << "ERROR : " << classObj << "::" << method << " : " << "  Error in data from params [" << errorMSG << "] \n"; \
   OutputDebugStringW( os_.str().c_str() );  \
   exit(1);                                  \
}

// Structures
struct
	SimpleVertex {
	XMFLOAT3 Pos;
	XMFLOAT2 Tex;
};

// Constant Buffers
struct
	CBNeverChanges {
	XMMATRIX mView;
};

// Representa la matriz de proyección
struct
	CBChangeOnResize {
	XMMATRIX mProjection;
};

// Representa la matriz del mundo
struct
	CBChangesEveryFrame {
	XMMATRIX mWorld;
	XMFLOAT4 vMeshColor;
};

// Enumeración de los tipos de extensión de las texturas
enum
	ExtensionType {
	DDS = 0,
	PNG = 1,
	JPG = 2,
	BMP = 3,
	TGA = 4,
	UNKNOWN = 5
};