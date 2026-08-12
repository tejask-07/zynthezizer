#include "raylib.h"
#include <cstddef>
#include <vector>

std::vector<Vector2> points;
bool showCenterLine = true;

int main() {
  const int screenWidth = 1280;
  const int screenHeight = 720;

  InitWindow(screenWidth, screenHeight, "drawWave");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_C)) {
      showCenterLine = !showCenterLine;
    }

    Vector2 mouse = GetMousePosition();

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
      points.push_back(mouse);
    }

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("C : toggle center line", 30, screenHeight - 40, 20, GRAY);

    if (showCenterLine) {
      DrawLine(0, screenHeight / 2, screenWidth, screenHeight / 2, GRAY);
    }

    DrawText("draw your waveform", 30, 30, 30, BLACK);
    DrawCircle(static_cast<int>(mouse.x), static_cast<int>(mouse.y), 5.0f, RED);

    for (size_t i = 1; i < points.size(); ++i) {
      DrawLineV(points[i - 1], points[i], BLACK);
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
