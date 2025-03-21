#include "Prerequisites.h"
#include "BaseApp.h"

// Global Variables
BaseApp                              g_app;

//--------------------------------------------------------------------------------------
// Entry point to the program. Initializes everything and goes into a message processing 
// loop. Idle time is used to render the scene.
//--------------------------------------------------------------------------------------

LRESULT CALLBACK
WndProc(HWND hWnd, unsigned int message, WPARAM wParam, LPARAM lParam) {


    PAINTSTRUCT ps;
    HDC hdc;

    switch (message) {
    case WM_PAINT:
        // Evento de repintado de ventana
        hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        break;

    case WM_SIZE:
        // Evento de redimensionamiento de ventana
        g_app.resize(hWnd, lParam);
        break;

    case WM_DESTROY:
        // Cerrar la aplicación
        PostQuitMessage(0);
        break;

    case WM_KEYDOWN:
        // Tecla presionada
        g_app.keys[wParam] = true;
        break;

    case WM_KEYUP:
         // Tecla liberada
        g_app.keys[wParam] = false;
        break;

    case WM_LBUTTONDOWN:
        // Botón izquierdo del mouse presionado
        g_app.mouseLeftDown = true;
        break;

    case WM_LBUTTONUP:
        // Botón izquierdo del mouse liberado
        g_app.mouseLeftDown = false;
        break;

    case WM_MOUSEMOVE:

        // Movimiento del mouse mientras se mantiene presionado el botón izquierdo
        if (g_app.mouseLeftDown) {
            int mouseX = LOWORD(lParam);
            int mouseY = HIWORD(lParam);
            g_app.rotateCamera(mouseX, mouseY);
        }
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}
int WINAPI
wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
    // Inicializar la aplicación
    return g_app.run(hInstance, hPrevInstance, lpCmdLine, nCmdShow, WndProc);
}