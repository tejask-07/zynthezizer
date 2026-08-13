#include "raylib.h"
#include <cstddef>
#include <vector>

std::vector<std::vector<Vector2>> strokes;
bool showCenterLine = true;

int main() {
  const int screenWidth = 1280;
  const int screenHeight = 720;

  InitWindow(screenWidth, screenHeight, "drawWave");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_R)) {
      strokes.clear();
    }

    if (IsKeyPressed(KEY_C)) {
      showCenterLine = !showCenterLine;
    }

    Vector2 mouse = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      strokes.push_back({});
    }

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && !strokes.empty()) {
      strokes.back().push_back(mouse);
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("C : toggle center line , R : Clear", 30, screenHeight - 40, 20,
             GRAY);

    if (showCenterLine) {
      DrawLine(0, screenHeight / 2, screenWidth, screenHeight / 2, GRAY);
    }

    DrawText("draw your waveform", 30, 30, 30, BLACK);
    DrawCircle(static_cast<int>(mouse.x), static_cast<int>(mouse.y), 5.0f, RED);

    for (const auto &stroke : strokes) {
      for (size_t i = 1; i < stroke.size(); ++i) {
        DrawLineV(stroke[i - 1], stroke[i], BLACK);
      }
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
