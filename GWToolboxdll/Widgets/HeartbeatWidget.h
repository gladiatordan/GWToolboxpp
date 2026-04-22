#pragma once

#include <ToolboxWidget.h>



class HeartbeatWidget : public ToolboxWidget {
    HeartbeatWidget() = default;
    ~HeartbeatWidget() override = default;

    public:
        static HeartbeatWidget& Instance()
        { 
            static HeartbeatWidget instance;
            return instance;
        }

        [[nodiscard]] const char* Name() const override { return "Heartbeat Timer"; }
        [[nodiscard]] const char* Icon() const override { return ICON_FA_HEARTBEAT; }

        void Draw(IDirect3DDevice9* pDevice) override;
};
