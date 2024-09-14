#include "engine.hpp"

// Constructor
Engine::Engine() {};

// Add objects to the engine
void Engine::AddObjects(const std::shared_ptr<Object> &obj){
    obj_arr.push_back(obj);
}

// Update objects and handle interactions
void Engine::Update(){
    Vector2 mousePos = GetMousePosition();

    // To click on an object
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        for(auto& obj : obj_arr){
            if(obj->CheckCollisionWithMouse()){
                selected_Obj = obj;
                obj->isDragging = true;
                break;
            }
        }
    }

    if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && !selected_Obj.expired()){
        if (auto selectedShared = selected_Obj.lock()){
            selectedShared->isDragging = false;
        }
        selected_Obj.reset();
    }

    if (auto selectedShared = selected_Obj.lock()) {
        if(selectedShared->isDragging){
            selectedShared->position = (Vector2){mousePos.x - selectedShared->width / 2, mousePos.y - selectedShared->height / 2};
        }
    }
    //-------------------------------------------------

    //AABB Updates
    //-------------------------------------------------
    for(auto& obj : obj_arr){
        obj->UpdateAABB();
    }

    if(AABBvsAABB(obj_arr[0]->aabb, obj_arr[1]->aabb)){
        obj_arr[1]->color = (Color){255, 0, 0, 255}; // Colision Detected Red
    } else {
        obj_arr[1]->color = (Color){0, 255, 0, 255}; // No Collision Detected Green
    }
    //-------------------------------------------------
}

// Render all Objects
void Engine::Draw() const {
    for(const auto& obj : obj_arr){
        obj->Draw();
    }
}

std::shared_ptr<Object> Engine::GetObject(int index) const {
    if(index >= 0 && index < obj_arr.size()){
        return obj_arr[index];
    }
    return nullptr;
}