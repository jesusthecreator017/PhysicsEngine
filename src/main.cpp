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

    for(int i = 0; i < 2; i++){
        Object obj;
        obj.GenerateRandomObject();
        obj_arr.push_back(obj);
    }

    // Object Pointer
    Object* SelectedObj = nullptr;

    //Main Game Loop
    while (!WindowShouldClose()){
        //Update
        //----------------------------------
        Vector2 mousePos = GetMousePosition();

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            for(auto& obj : obj_arr){
                if(obj.CheckCollisionWithMouse()){
                    SelectedObj = &obj;
                    obj.isDragging = true;
                    break;
                }
            }
        }

        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && SelectedObj != nullptr){
            SelectedObj->isDragging = false;
            SelectedObj = nullptr;
        }

        if (SelectedObj != nullptr && SelectedObj->isDragging) {
            SelectedObj->position = (Vector2){mousePos.x - SelectedObj->width / 2, mousePos.y - SelectedObj->height / 2};
        }

        

        //----------------------------------

        //Draw
        //----------------------------------
        BeginDrawing();
            ClearBackground((Color){108, 89, 110, 255});
            for(auto& obj : obj_arr){
                obj.Draw();
            }
            obj_arr[0].Print(0, 0);
            obj_arr[1].Print(940, 0);
        EndDrawing();
        //----------------------------------
    }
    CloseWindow();
}
