#include "raylib.h"

int main() {
  const int screenHeight = 800;
  const int screenWidth = 650;

  InitWindow(screenWidth, screenHeight, "basic window");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("window hai ji <3", 190, 200, 20, LIGHTGRAY);
    DrawText("press esc to exit", 190, 240, 20, DARKGRAY);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
