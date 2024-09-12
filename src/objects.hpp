#include <iostream>
#include "raylib.h"
#include "raymath.h"

// Axis Aligned Bounding Box
//--------------------------------------------------
struct AABB{
    Vector2 min;
    Vector2 max;
};

bool AABBvsAABB(AABB a, AABB b);
//--------------------------------------------------

// Objects
//--------------------------------------------------
class Object{
private:  
    AABB aabb;
    u_int8_t mass; // Max: 255
    float restitution; // EX: 65536

public:
    Vector2 position; // EX: (124, 245)
    Vector2 velocity; // EX: (1, -1)
    Vector2 acceleration; // EX: (.013, 0.1234)

    u_int16_t iD; // EX: 65536 

    u_int16_t width; // Max: 255
    u_int16_t height; // Max: 255

    Color color; // EX: (255, 255, 255, 255) Full White

    bool isDragging = false;
    bool colliding = false;

    // Constructor
    Object();
    Object(Vector2 pos, Vector2 vel, Vector2 accel, u_int8_t m, float res, u_int16_t id, u_int8_t w, u_int8_t h, Color col);

    // Class Functions
    void GenerateRandomObject();
    void Print(u_int16_t x_offset, u_int16_t y_offset);
    void Draw();

    bool CheckCollisionWithMouse();
};
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