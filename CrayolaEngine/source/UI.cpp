#include "UI.h"
#include "Prerequisites.h"
#include "BaseApp.h"

extern BaseApp g_app; 

void
UI::init(void* window, ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;        // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    // Setup Dear ImGui style
    baseStyleGUI();

    // Setup Dear ImGui style
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    // Setup Platform/Renderer bindings
    ImGui_ImplWin32_Init(window);
    ImGui_ImplDX11_Init(device, deviceContext);

}
void
UI::update()
{
    // Start the Dear ImGui frame
    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
}

void
UI::render()
{
    // Rendering
    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
    }
}

void
UI::destroy()
{
    // Cleanup
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
}

void
UI::renderWindow() {
    ImGui::Begin("Comienza el fornait");
    ImGui::Text("De pelos rey");
    ImGui::End();
}

void
UI::Inspector()
{
    // Crea una nueva ventana
    ImGui::Begin("Cube Transform");

    // Controles para la posici�n del cubo
    ImGui::Text("Position");
    ImGui::DragFloat3("Position", reinterpret_cast<float*>(&g_app.position), 0.1f);

    // Controles para la rotaci�n del cubo
    ImGui::Text("Rotation");
    ImGui::DragFloat3("Rotation", reinterpret_cast<float*>(&g_app.rotation), 0.1f);

    // Controles para la escala del cubo
    ImGui::Text("Scale");
    ImGui::DragFloat3("Scale", reinterpret_cast<float*>(&g_app.scale), 0.1f);

    // Termina la ventana
    ImGui::End();
}

void
UI::baseStyleGUI() {
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    colors[ImGuiCol_Text] = ImVec4(0.9f, 0.2f, 0.2f, 1.00f);              // Texto (rojo claro)
    colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1f, 0.25f, 1.00f);         // Fondo ventana (azul oscuro)
    colors[ImGuiCol_Button] = ImVec4(0.2f, 0.2f, 0.5f, 1.00f);            // Botón (azul)
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.4f, 0.2f, 0.6f, 1.00f);     // Hover (púrpura suave)
    colors[ImGuiCol_ButtonActive] = ImVec4(0.7f, 0.2f, 0.3f, 1.00f);      // Activo (rojo violáceo)
    colors[ImGuiCol_FrameBg] = ImVec4(0.15f, 0.15f, 0.35f, 1.00f);        // Fondo de frame
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.3f, 0.2f, 0.4f, 1.00f);    // Hover frame
    colors[ImGuiCol_TitleBg] = ImVec4(0.1f, 0.1f, 0.3f, 1.00f);           // Título
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.3f, 0.0f, 0.3f, 1.00f);     // Título activo (púrpura oscuro)

    colors[ImGuiCol_Border] = ImVec4(0.3f, 0.1f, 0.1f, 1.00f);            // Bordes (rojo apagado)
    colors[ImGuiCol_CheckMark] = ImVec4(1.0f, 0.1f, 0.1f, 1.00f);         // Check rojo brillante
    colors[ImGuiCol_SliderGrab] = ImVec4(0.2f, 0.3f, 0.9f, 1.00f);        // Azul fuerte
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.6f, 0.2f, 0.9f, 1.00f);  // Activo más morado
    colors[ImGuiCol_Separator] = ImVec4(0.4f, 0.0f, 0.2f, 1.00f);         // Separador vino

    colors[ImGuiCol_Tab] = ImVec4(0.2f, 0.2f, 0.5f, 1.00f);               // Azul
    colors[ImGuiCol_TabHovered] = ImVec4(0.5f, 0.2f, 0.5f, 1.00f);        // Púrpura claro
    colors[ImGuiCol_TabActive] = ImVec4(0.7f, 0.1f, 0.3f, 1.00f);         // Rojo oscuro
    colors[ImGuiCol_Header] = ImVec4(0.2f, 0.2f, 0.4f, 1.00f);            // Azul oscuro
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.4f, 0.3f, 0.6f, 1.00f);     // Hover con mezcla
    colors[ImGuiCol_HeaderActive] = ImVec4(0.7f, 0.2f, 0.2f, 1.00f);      // Rojo fuerte

    colors[ImGuiCol_PopupBg] = ImVec4(0.1f, 0.1f, 0.25f, 1.00f);          // Azul oscuro popup


    // Ajustes de estilo general
    style.WindowRounding = 5.0f;   // Redondeo de bordes de ventanas
    style.FrameRounding = 5.0f;   // Redondeo de bordes de cuadros
    style.ScrollbarRounding = 5.0f;   // Redondeo de bordes de scrollbar
    style.GrabRounding = 5.0f;   // Redondeo de bordes de botones de agarrar
    style.FrameBorderSize = 1.0f;   // Grosor del borde de cuadros
    style.WindowBorderSize = 1.0f;   // Grosor del borde de ventanas
    style.PopupBorderSize = 1.0f;   // Grosor del borde de popups
}