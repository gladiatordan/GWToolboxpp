#include "stdafx.h"
#include "HeartbeatWidget.h"

#include <GWCA/Managers/MapMgr.h>
#include <GWCA/Constants/Constants.h>

#include <Utils/FontLoader.h>



void HeartbeatWidget::Draw(IDirect3DDevice9*)
{
    if (!visible) {
        return;
    }

    // Only active in explorable areas
    if (GW::Map::GetInstanceType() != GW::Constants::InstanceType::Explorable) {
        return;
    }

    char buffer[32];
    ImColor extra_color = 0;
    const uint32_t instance_time = GW::Map::GetInstanceTime();
    const uint32_t temp = (instance_time - 1000) % 3000;
    const uint32_t remaining_time = 3000 - temp;
    if (remaining_time > 1500)
    {
        extra_color = ImColor(255, 0, 0);
    }
    else 
    {
        extra_color = ImColor(0, 255, 0);
    }
    snprintf(buffer, 32, "%.1f", remaining_time / 1000.0f);

    // Draw the UI
    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 0));
    ImGui::SetNextWindowSize(ImVec2(200.0f, 90.0f), ImGuiCond_FirstUseEver);

    if (ImGui::Begin(Name(), nullptr, GetWinFlags())) {
        // draw header
        ImGui::PushFont(FontLoader::GetFont(FontLoader::FontSize::header1));
        ImVec2 cur = ImGui::GetCursorPos();
        ImGui::SetCursorPos(ImVec2(cur.x + 1, cur.y + 1));
        ImGui::TextColored(ImColor(0, 0, 0), "Heartbeat");
        ImGui::SetCursorPos(cur);
        ImGui::Text("Heartbeat");
        ImGui::PopFont();

        // timer text
        ImGui::PushFont(FontLoader::GetFont(FontLoader::FontSize::widget_large));
        cur = ImGui::GetCursorPos();
        ImGui::SetCursorPos(ImVec2(cur.x + 2, cur.y + 2));
        ImGui::TextColored(ImColor(0, 0, 0), buffer);
        ImGui::SetCursorPos(cur);
        ImGui::TextColored(extra_color, buffer);
        ImGui::PopFont();
    }
    ImGui::End();
    ImGui::PopStyleColor();
}
