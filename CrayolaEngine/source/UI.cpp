#include "UI.h"
#include "Window.h"
#include "Device.h"
#include "DeviceContext.h"
#include "BaseApp.h"
#include "ECS/Transform.h"

extern BaseApp g_app;

void UI::init(void* window, ID3D11Device* device, ID3D11DeviceContext* deviceContext)
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

void UI::update()
{
    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
}

void UI::render()
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

void UI::destroy()
{
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
}

void UI::renderWindow()
{
    ImGui::Begin("Comienza el fornait");
    ImGui::Text("De pelos rey");
    ImGui::End();
}

void UI::Inspector()
{
    ImGui::Begin("Inspector");

    auto actor = g_app.ALethal;
    if (!actor.isNull()) {
        auto transform = actor->getComponent<Transform>();
        if (!transform.isNull()) {
            TransformGUI(*transform);
        }
        else {
            ImGui::Text("Transform component not found.");
        }
    }
    else {
        ImGui::Text("No actor found.");
    }

    ImGui::End();
}

void UI::TransformGUI(Transform& transform)
{
    ImGui::Begin("Transform");

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

    ImGui::End();
}

void UI::baseStyleGUI()
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

void UI::vec3Control(const std::string& label, float* values, float resetValues, float columnWidth)
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
