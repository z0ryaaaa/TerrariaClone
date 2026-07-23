#include "raylib.h"
#include "imgui.h"
#include "rlImGui.h"

int main() {
    InitWindow(800, 450, "Terraria Clone");
    rlImGuiSetup(true); // true = dark theme

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        rlImGuiBegin();
        ImGui::ShowDemoWindow(); // sanity check — remove once it's working
        rlImGuiEnd();

        EndDrawing();
    }

    rlImGuiShutdown();
    CloseWindow();
    return 0;
}
