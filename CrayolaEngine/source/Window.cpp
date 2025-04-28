#include "Window.h"

/**
 * @brief Inicializa y crea una ventana de Win32 para la aplicación.
 * @param hInstance Instancia de la aplicación.
 * @param nCmdShow Modo de visualización de la ventana.
 * @param wndproc Procedimiento de ventana (callback para eventos).
 * @return HRESULT indicando éxito o error.
 */
HRESULT
Window::init(HINSTANCE hInstance, int nCmdShow, WNDPROC wndproc) {
    // Guardar la instancia de la aplicación
    m_hInst = hInstance;

    // Registrar la clase de ventana
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;   // Redibujar en cambios de tamaño
    wcex.lpfnWndProc = wndproc;     // Procedimiento para eventos
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = m_hInst;
    wcex.hIcon = LoadIcon(m_hInst, (LPCTSTR)IDI_TUTORIAL1); // Icono grande
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);          // Cursor por defecto
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);        // Color de fondo
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "TutorialWindowClass";         // Nombre de la clase de ventana
    wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_TUTORIAL1); // Icono pequeño

    if (!RegisterClassEx(&wcex)) {
        MessageBox(nullptr, "RegisterClassEx failed!", "Error", MB_OK);
        ERROR("Window", "init", "CHECK FOR RegisterClassEx");
        return E_FAIL;
    }

    //  Crear la ventana
    RECT rc = { 0, 0, 1280, 720 };
    m_rect = rc;

    // Ajustar tamaño del rectángulo considerando bordes y título
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

    m_hWnd = CreateWindow("TutorialWindowClass",
        m_windowName.c_str(),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        m_rect.right - m_rect.left,
        m_rect.bottom - m_rect.top,
        NULL,
        NULL,
        m_hInst,
        NULL);
    if (!m_hWnd) {
        MessageBox(nullptr, "CreateWindow failed!", "Error", MB_OK);
        ERROR("Window", "init", "CHECK FOR CreateWindow()");
        return E_FAIL;
    }

    // Mostrar y actualizar la ventana  
    ShowWindow(m_hWnd, nCmdShow);
    UpdateWindow(m_hWnd);

    // SetUp Viewport Dimensions
    GetClientRect(m_hWnd, &m_rect);
    m_width = m_rect.right - m_rect.left;
    m_height = m_rect.bottom - m_rect.top;

    return S_OK;
}