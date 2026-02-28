#pragma once

#include "ToolboxWindow.h"

class GWAMMSCWindow : public ToolboxWindow {
    GWAMMSCWindow() = default;
    ~GWAMMSCWindow() override = default;

public:
    static GWAMMSCWindow& Instance()
    {
        static GWAMMSCWindow instance;
        return instance;
    }

    [[nodiscard]] const char* Name() const override { return "GWAMMSC"; }
    [[nodiscard]] const char* Description() const override { return "Keeps track of GWAMMSC route information."; }
    [[nodiscard]] const char* Icon() const override { return ICON_FA_TROPHY; }

    // Optional for now; included for consistency with other windows
    void Terminate() override { ToolboxWindow::Terminate(); }

    void Draw(IDirect3DDevice9* device) override;

    void LoadSettings(ToolboxIni* ini) override { ToolboxWindow::LoadSettings(ini); };
    void SaveSettings(ToolboxIni* ini) override { ToolboxWindow::SaveSettings(ini); };
};
