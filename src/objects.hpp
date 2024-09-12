#include <iostream>
#include "raylib.h"
#include "raymath.h"

// Objects
//--------------------------------------------------
class Object{
private:
    Vector2 position; // EX: (124, 245)
    Vector2 velocity; // EX: (1, -1)
    Vector2 acceleration; // EX: (.013, 0.1234)
    
    uint8_t mass; // Max: 255
    uint16_t restitution; // EX: 65536

public:
    uint16_t iD; // EX: 65536 

    uint8_t width; // Max: 255
    uint8_t height; // Max: 255

    Color color; // EX: (255, 255, 255, 255) Full White

    // Constructor
    Object();
    Object(Vector2 pos, Vector2 vel, Vector2 accel, uint8_t m, uint16_t res, uint16_t id, uint8_t w, uint8_t h, Color col);

    // Class Functions
    void GenerateRandomObject();
    void Print(uint16_t x_offset, uint16_t y_offset);
    void Draw();
};
//--------------------------------------------------

// Axis Aligned Bounding Box
//--------------------------------------------------
struct AABB{
    Vector2 min;
    Vector2 max;
};

bool AABBvsAABB(AABB a, AABB b);
//--------------------------------------------------

// Particle
//--------------------------------------------------
struct Particle{
    float radius;
    Vector2 position;
};

float Distance(Vector2 a, Vector2 b);
bool CirclevsCircleUnoptimized(Particle a, Particle b);
//--------------------------------------------------