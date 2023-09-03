#include "Arena.hpp"

Arena::Arena() {

}

void Arena::start() {

}

void Arena::end() {

}

void Arena::init(Engine::Window *windowPtr, Engine::Data *dataPtr) {
    this->windowPtr = windowPtr;
    this->dataPtr = dataPtr;

    //object loading
    this->backgroundDrawing.initialize(dataPtr->getTexture("bg.jpg"), windowPtr->getWindowPtr());
    this->backgroundDrawing.resizeTo(windowPtr->getWindowSize());

    this->entity.init(windowPtr, dataPtr);
    this->entity.setExternalPosition({(float)windowPtr->getWindowSize().x / 2,
                                      (float)windowPtr->getWindowSize().y / 2});
    this->entity.rotateExternalBy(-90);

    //horizontal, up
    boundsCollision.addPlane({{0, 0}, {(float)windowPtr->getWindowSize().x, 0}});

    //horizontal, down
    boundsCollision.addPlane({{0, (float)windowPtr->getWindowSize().y},
                              {(float)windowPtr->getWindowSize().x, (float)windowPtr->getWindowSize().y}});

    //vertical, left
    boundsCollision.addPlane({{0, 0},
                              {0, (float)windowPtr->getWindowSize().y}});

    //vertical, right
    boundsCollision.addPlane({{(float)windowPtr->getWindowSize().x, 0},
                              {(float)windowPtr->getWindowSize().x, (float)windowPtr->getWindowSize().y}});

}

void Arena::draw() {
    this->backgroundDrawing.drawTo();
    this->entity.draw();

    if (boundsCollision.isColliding(entity.collisionHandler)){
        entity.restrictCollision(0, 0);
    }

}
