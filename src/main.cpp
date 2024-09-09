#include "raylib.h"

int main() {
    // Initialize the window
    InitWindow(800, 600, "Hello Raylib");

    // Main game loop
    while (!WindowShouldClose()) {  // Detect window close button or ESC key
        BeginDrawing();
        ClearBackground((Color){245, 245, 245, 255});  // RAYWHITE equivalent
        DrawText("Welcome to Raylib!", 190, 200, 20, (Color){200, 200, 200, 255});  // LIGHTGRAY equivalent
        EndDrawing();
    }

    // Deinitialize
    CloseWindow();
    return 0;
}
