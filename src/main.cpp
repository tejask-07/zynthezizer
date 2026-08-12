#include "raylib.h"

int main() {
  const int screenHeight = 1280;
  const int screenWidth = 720;

  InitWindow(screenWidth, screenHeight, "drawWave");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    Vector2 mouse = GetMousePosition();

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("draw your waveform", 30, 30, 30, BLACK);
    DrawCircle(static_cast<int>(mouse.x), static_cast<int>(mouse.y), 5.0f, RED);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
