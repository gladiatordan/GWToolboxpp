#include "stdafx.h"

#include <Windows/GWAMMSCWindow.h>

void GWAMMSCWindow::Draw(IDirect3DDevice9*)
{
    if (!visible) {
        return;
    }

    ImGui::SetNextWindowSize(ImVec2(420.0f, 240.0f), ImGuiCond_FirstUseEver);

    if (ImGui::Begin(Name(), GetVisiblePtr(), GetWinFlags())) {
        ImGui::TextUnformatted("GWAMMSC window stub.");
        ImGui::Separator();
        ImGui::TextUnformatted("Hook is working; add UI here next.");
    }
    ImGui::End();
}
