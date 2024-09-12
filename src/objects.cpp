#include "objects.hpp"

//Objects
//-------------------------------------------------------------------------

// Constructor
Object::Object(){
    GenerateRandomObject();
}

Object::Object(Vector2 pos, Vector2 vel, Vector2 accel, uint8_t m, uint16_t res, uint16_t id, uint8_t w, uint8_t h, Color col){
    position = pos;
    velocity = vel;
    acceleration = accel;
    mass = m;
    restitution = res;
    iD = id;
    width = w;
    height = h;
    color = col;
}

// Generate a random Value
void Object::GenerateRandomObject(){
    /* Purpose: Generate Random Values for an object
       Parameters: None */

    position = (Vector2){static_cast<float>(GetRandomValue(0, 1200 - width)), static_cast<float>(GetRandomValue(0, 720 - height))};
    velocity = (Vector2){static_cast<float>(GetRandomValue(0, 1)), static_cast<float>(GetRandomValue(0, 1))};
    acceleration = (Vector2){0, 0};
    
    mass = static_cast<uint8_t>(GetRandomValue(0, 255));
    width = GetRandomValue(200, 800);
    height = GetRandomValue(200, 400);

    restitution = GetRandomValue(0, 65536);
    iD = GetRandomValue(0, 65536);
    
    color = (Color){static_cast<uint8_t>(GetRandomValue(0, 255)), static_cast<uint8_t>(GetRandomValue(0, 255)), static_cast<uint8_t>(GetRandomValue(0, 255)), 255};
}

void Object::Print(uint16_t x_offset=0, uint16_t y_offset=0){
   /* Purpose: To display the information on a specific object*/
   DrawRectangle(5 + x_offset, 5 + y_offset, 250, 140, (Color){90, 70, 90, 155});
   DrawText(TextFormat("Position: (%0.2f, %0.2f)\nVelocity: (%0.2f, %0.2f)\nAcceleration: (%0.2f, %0.2f)\nMass: %i\nRestitution: %i\nWidth: %i\nHeight: %i\nColor: (%i, %i, %i, %i)", position.x, position.y, velocity.x, velocity.y, acceleration.x, acceleration.y, mass, restitution, width, height, color.r, color.g, color.b, color.a), 10 + x_offset, 10 + y_offset, 18, (Color){255, 255, 255, 255});
}

void Object::Draw(){
    DrawRectangle(position.x, position.y, width, height, color);
}
//-------------------------------------------------------------------------


// AABB
//-------------------------------------------------------------------------
bool AABBvsAABB(AABB a, AABB b){
    /* Checks if there is a collision between to Axis Aligned Bounding Boxes
       Returns a Boolean, parameters are 2 AABB*/ 

    // Exits with no intersecting Axises 
    if(a.max.x < b.min.x or a.min.x > b.max.x) return false;
    if(a.max.y < b.min.y or a.min.y > b.max.y) return false;

    // No seperating Axises, at least 1 collision happening
    return true;
}
//-------------------------------------------------------------------------

// Particle
//-------------------------------------------------------------------------
float Distance(Vector2 a, Vector2 b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool ParticlevsParticleUnoptimized(Particle a, Particle b){
    float r = a.radius + b.radius;
    return r < Distance(a.position, b.position);
}

bool ParticlevsParticleOptimized(Particle a, Particle b){
    float r = a.radius + b.radius;
    r *= r;
    return r < pow(a.position.x + b.position.x, 2) + pow(a.position.y + b.position.y, 2);
}
//-------------------------------------------------------------------------
