#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <vector>
#include <memory>
#include "raylib.h"
#include "objects.hpp"

class Engine{
public:
    Engine();   // Constructor

    // Add objects to the engine
    void AddObjects(const std::shared_ptr<Object> &obj);

    // Update all objects and handle interactions
    void Update();

    // Render all objects
    void Draw() const;

    // Access an object for debugging or additional functions
    std::shared_ptr<Object> GetObject(int index) const;

private:
    std::vector<std::shared_ptr<Object>> obj_arr;
    std::weak_ptr<Object> selected_Obj;
};

#endif