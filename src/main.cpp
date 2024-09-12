#include <vector>
#include "raylib.h"
#include "objects.hpp"

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 720

int main() {
    // Initialize the Window
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "2D Physics Engine");

    // Set Frames
    SetTargetFPS(60);

    // Set the random generator
    SetRandomSeed((uint16_t)time(NULL));

    // Generate Objects
    std::vector<Object> obj_arr;

    for(int i = 0; i < 5; i++){
        Object obj;
        obj.GenerateRandomObject();
        obj_arr.push_back(obj);
    }

    //Main Game Loop
    while (!WindowShouldClose()){
        //Update
        //----------------------------------
        
        //Code
        //----------------------------------

        //Draw
        //----------------------------------
        BeginDrawing();
            ClearBackground((Color){108, 89, 110, 255});
            for(auto& obj : obj_arr){
                obj.Draw();
            }
            obj_arr[0].Print(0, 0);
        EndDrawing();
        //----------------------------------
    }
    CloseWindow();
}
