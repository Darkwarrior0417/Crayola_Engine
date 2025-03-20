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
        hdc = BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        break;

    case WM_SIZE:
        g_app.resize(hWnd, lParam);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_KEYDOWN:
        g_app.keys[wParam] = true;
        break;
    case WM_KEYUP:
        g_app.keys[wParam] = false;
        break;
    case WM_LBUTTONDOWN:
        g_app.mouseLeftDown = true;
        break;
    case WM_LBUTTONUP:
        g_app.mouseLeftDown = false;
        break;
    case WM_MOUSEMOVE:

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