#ifndef NFFSMODULE_ARENA_HPP
#define NFFSMODULE_ARENA_HPP

#include "../src/Drawing.hpp"

#include "../src/Window.hpp"

#include "../src/Data.hpp"

#include "ControlledEntity.hpp"

#include "../src/CollisionHandler.hpp"

class Arena{
public:
    Arena();

    void init(Engine::Window *windowPtr, Engine::Data *dataPtr);

    void draw();

    void start();

    void end();

private:
    Engine::Window *windowPtr;
    Engine::Data *dataPtr;

    Engine::Drawing backgroundDrawing;

    ControlledEntity entity;

    Engine::CollisionHandler boundsCollision;

};


#endif //NFFSMODULE_ARENA_HPP
