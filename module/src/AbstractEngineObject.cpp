#include "AbstractEngineObject.hpp"

AbstractEngineObject::AbstractEngineObject() {

}

void AbstractEngineObject::addState(std::string stateName, bool originalValue) {
    states.insert({stateName, originalValue});
}

bool AbstractEngineObject::getState(std::string stateName) {
    return states[stateName];
}

bool AbstractEngineObject::getStateSingle(std::string stateName) {
    bool returnState = states[stateName];
    setState(stateName, false);
    return returnState;
}

void AbstractEngineObject::setState(std::string stateName, bool value) {
    states[stateName] = value;
}

void AbstractEngineObject::resetState(std::string stateName) {
    states[stateName] = false;
}

void AbstractEngineObject::invertState(std::string stateName) {
    states[stateName] = !states[stateName];
}

void AbstractEngineObject::update() {
    processEventsImpl();
    updateImpl();
}

void AbstractEngineObject::updateImpl() {

}

void AbstractEngineObject::processEvents() {
    processEventsImpl();
}

void AbstractEngineObject::processEventsImpl() {

}

void AbstractEngineObject::draw() {

}


void AbstractEngineObject::create(Engine::Window *windowPtr,  Engine::Data *dataPtr) {
    this->windowPtr = windowPtr->getWindowPtr();
    this->dataPtr = dataPtr;
    this->windowEventPtr = windowPtr->getLatestEvent();
    this->deltaPtr = windowPtr->getDeltaTimePtr();

    createImpl(windowPtr, dataPtr);
}

void AbstractEngineObject::createImpl(Engine::Window *windowPtr, Engine::Data *dataPtr) {

}




