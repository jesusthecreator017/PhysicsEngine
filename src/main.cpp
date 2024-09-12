#include "engine.hpp"

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 720

int main() {
    // Initialize the Window
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "2D Physics Engine");

    // Set Frames
    SetTargetFPS(60);

    // Set the random generator
    SetRandomSeed((u_int16_t)time(NULL));

    // Start the engine
    Engine engine;

    engine.AddObjects(std::make_shared<Object>());
    engine.AddObjects(std::make_shared<Object>());

    //Main Game Loop
    while (!WindowShouldClose()){
        // Update the engine
        engine.Update();

        //Draw
        BeginDrawing();
            ClearBackground((Color){108, 89, 110, 255});
            engine.Draw();
            
            engine.GetObject(0)->Print(0, 0);
            engine.GetObject(1)->Print(940, 0);
        EndDrawing();
    }
    CloseWindow();
}
