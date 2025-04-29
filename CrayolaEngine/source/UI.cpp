#include "UI.h"
#include "Window.h"
#include "Device.h"
#include "DeviceContext.h"
#include "BaseApp.h"
#include "ECS/Transform.h"

extern 
BaseApp g_app;

/**
 * @brief Inicializa ImGui con la ventana y dispositivos de DirectX 11.
 */
void 
UI::init(void* window, ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    baseStyleGUI();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    ImGui_ImplWin32_Init(window);
    ImGui_ImplDX11_Init(device, deviceContext);
}


/**
 * @brief Prepara una nueva frame para dibujar UI.
 */
void
UI::update()
{
    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
}

/**
 * @brief Renderiza la UI en pantalla.
 */
void 
UI::render()
{
    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
    }
}

/**
 * @brief Libera recursos de ImGui.
 */
void
UI::destroy()
{
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
}

/**
 * @brief Renderiza una ventana de prueba simple.
 */
void 
UI::renderWindow()
{
    ImGui::Begin("Comienza el fornait");
    ImGui::Text("De pelos rey");
    ImGui::End();
}

/**
 * @brief Renderiza el panel de Inspector para ver/editar el Transform del Actor seleccionado.
 */
void 
UI::Inspector()
{
    ImGui::Begin("Inspector");

    if (!g_app.m_selectedActor.isNull()) { // ← Aquí ya estás trabajando solo sobre m_selectedActor
        auto transform = g_app.m_selectedActor->getComponent<Transform>();
        if (!transform.isNull()) {
            TransformGUI(*transform);
        }
        else {
            ImGui::Text("Transform component not found.");
        }
    }
    else {
        ImGui::Text("No actor selected.");
    }

    ImGui::End();
}

/**
 * @brief Dibuja controles de posición, rotación y escala para un Transform.
 * @param transform Transform a modificar.
 */
void 
UI::TransformGUI(Transform& transform)
{
    ImGui::Begin("Transform");

    // Hacer que cada Transform tenga un ID único basado en su puntero
    ImGui::PushID(&transform);

    EngineUtilities::Vector3 pos = transform.getPosition();
    EngineUtilities::Vector3 rot = transform.getRotation();
    EngineUtilities::Vector3 sca = transform.getScale();

    if (ImGui::DragFloat3("Position", &pos.x, 0.1f)) {
        transform.setPosition(pos);
    }

    if (ImGui::DragFloat3("Rotation", &rot.x, 0.1f)) {
        transform.setRotation(rot);
    }

    if (ImGui::DragFloat3("Scale", &sca.x, 0.1f)) {
        transform.setScale(sca);
    }

    ImGui::PopID(); // Importante para no afectar otras ventanas o ImGui widgets

    ImGui::End();
}

/**
 * @brief Aplica un estilo visual personalizado a la interfaz de ImGui.
 */
void 
UI::baseStyleGUI()
{
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    colors[ImGuiCol_Text] = ImVec4(0.9f, 0.2f, 0.2f, 1.00f);
    colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1f, 0.25f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.2f, 0.2f, 0.5f, 1.00f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.4f, 0.2f, 0.6f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.7f, 0.2f, 0.3f, 1.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.15f, 0.15f, 0.35f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.3f, 0.2f, 0.4f, 1.00f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.1f, 0.1f, 0.3f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.3f, 0.0f, 0.3f, 1.00f);
    colors[ImGuiCol_Border] = ImVec4(0.3f, 0.1f, 0.1f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(1.0f, 0.1f, 0.1f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.2f, 0.3f, 0.9f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.6f, 0.2f, 0.9f, 1.00f);
    colors[ImGuiCol_Separator] = ImVec4(0.4f, 0.0f, 0.2f, 1.00f);
    colors[ImGuiCol_Tab] = ImVec4(0.2f, 0.2f, 0.5f, 1.00f);
    colors[ImGuiCol_TabHovered] = ImVec4(0.5f, 0.2f, 0.5f, 1.00f);
    colors[ImGuiCol_TabActive] = ImVec4(0.7f, 0.1f, 0.3f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.2f, 0.2f, 0.4f, 1.00f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.4f, 0.3f, 0.6f, 1.00f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.7f, 0.2f, 0.2f, 1.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.1f, 0.1f, 0.25f, 1.00f);

    style.WindowRounding = 5.0f;
    style.FrameRounding = 5.0f;
    style.ScrollbarRounding = 5.0f;
    style.GrabRounding = 5.0f;
    style.FrameBorderSize = 1.0f;
    style.WindowBorderSize = 1.0f;
    style.PopupBorderSize = 1.0f;
}

/**
 * @brief Muestra una lista de actores para seleccionar cuál editar en el Inspector.
 */
void 
UI::ActorSelector()
{   
    // Inicia una nueva ventana de ImGui llamada "Actor Selector"
    ImGui::Begin("Actor Selector");

    // Estructura auxiliar que guarda un actor y su nombre visible en la lista
    struct ActorOption {
        EngineUtilities::TSharedPointer<Actor> actor;
        std::string displayName;
    };

    // Vector de actores disponibles para seleccionar
    std::vector<ActorOption> actors = {
        { g_app.ALethal, "OmniMan" },
        { g_app.AStorm, "Stormtrooper" },
        { g_app.AChaos, "Peely" }
    };

    int id = 0;
    for (auto& actorOption : actors) {
        if (!actorOption.actor.isNull()) {
            // Mostrar nombre visible + ID único interno para ImGui
            std::string label = actorOption.displayName + "##" + std::to_string(id++);
            bool isSelected = (g_app.m_selectedActor == actorOption.actor);

            // Dibuja un botón "selectable" con el nombre y el ID único
            if (ImGui::Selectable(label.c_str(), isSelected)) {
                g_app.m_selectedActor = actorOption.actor;
            }
        }
    }

    // Termina la ventana de ImGui
    ImGui::End();
}

/**
 * @brief Control personalizado para editar un vector3 (posición, rotación o escala) en UI.
 * @param label Texto del control.
 * @param values Puntero al array de 3 floats (X, Y, Z).
 * @param resetValues Valor por defecto al reiniciar.
 * @param columnWidth Ancho de la primera columna.
 */
void 
UI::vec3Control(const std::string& label, float* values, float resetValues, float columnWidth)
{
    ImGuiIO& io = ImGui::GetIO();
    auto boldFont = io.Fonts->Fonts[0];

    ImGui::PushID(label.c_str());

    ImGui::Columns(2);
    ImGui::SetColumnWidth(0, columnWidth);
    ImGui::Text(label.c_str());
    ImGui::NextColumn();

    ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{ 0, 0 });

    float lineHeight = GImGui->Font->FontSize + GImGui->Style.FramePadding.y * 2.0f;
    ImVec2 buttonSize = { lineHeight + 3.0f, lineHeight };

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.8f, 0.1f, 0.15f, 1.0f });
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.9f, 0.2f, 0.2f, 1.0f });
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.8f, 0.1f, 0.15f, 1.0f });
    ImGui::PushFont(boldFont);
    if (ImGui::Button("X", buttonSize)) values[0] = resetValues;
    ImGui::PopFont();
    ImGui::PopStyleColor(3);

    ImGui::SameLine();
    ImGui::DragFloat("##X", &values[0], 0.1f, 0.0f, 0.0f, "%.2f");
    ImGui::PopItemWidth();
    ImGui::SameLine();

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.2f, 0.7f, 0.2f, 1.0f });
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.3f, 0.8f, 0.3f, 1.0f });
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.2f, 0.7f, 0.2f, 1.0f });
    ImGui::PushFont(boldFont);
    if (ImGui::Button("Y", buttonSize)) values[1] = resetValues;
    ImGui::PopFont();
    ImGui::PopStyleColor(3);

    ImGui::SameLine();
    ImGui::DragFloat("##Y", &values[1], 0.1f, 0.0f, 0.0f, "%.2f");
    ImGui::PopItemWidth();
    ImGui::SameLine();

    ImGui::PopStyleVar();
    ImGui::Columns(1);
    ImGui::PopID();
}
