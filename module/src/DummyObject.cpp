#include "DummyObject.hpp"

DummyObject::DummyObject() {

}

void DummyObject::draw() {
    drawing.drawTo();
}

void DummyObject::updateImpl() {
    if (getStateSingle("click")){
        drawing.moveBy({50, 0});
    }

    if (getStateSingle("drag")){
        drawing.setPosition({(float)sf::Mouse::getPosition(*windowPtr).x, (float)sf::Mouse::getPosition(*windowPtr).y});
    }
}

void DummyObject::processEventsImpl() {
    if (windowEventPtr->type == sf::Event::MouseButtonPressed && windowEventPtr->mouseButton.button == sf::Mouse::Left)
        setState("click", true);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
        setState("drag", true);
}

void DummyObject::createImpl(sf::RenderWindow *windowPtr, Engine::Data *dataPtr, sf::Event *windowEventPtr) {
    drawing.initialize(dataPtr->getTexture("1.png"), windowPtr);
}


