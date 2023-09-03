#include "DummyObject.hpp"

DummyObject::DummyObject() {

}

void DummyObject::draw() {
    drawing.drawTo();
    text.drawTo();
}

void DummyObject::updateImpl() {
    if (getStateSingle("click")){
        drawing.moveBy({50, 0});
    }

    if (getStateSingle("drag")){
        drawing.setPosition({(float)sf::Mouse::getPosition(*windowPtr).x, (float)sf::Mouse::getPosition(*windowPtr).y});
        text.setPosition({(float)sf::Mouse::getPosition(*windowPtr).x, (float)sf::Mouse::getPosition(*windowPtr).y});
    }
}

void DummyObject::processEventsImpl() {
    //Maybe move it to base method?
    if (windowEventPtr->type == sf::Event::MouseButtonPressed && windowEventPtr->mouseButton.button == sf::Mouse::Left)
        setState("click", true);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
        setState("drag", true);
}

void DummyObject::createImpl(Engine::Window *windowPtr,  Engine::Data *dataPtr) {
    drawing.initialize(dataPtr->getTexture("1.png"), windowPtr->getWindowPtr());

    text.init(windowPtr->getWindowPtr(), dataPtr->getFont("arial.ttf"), {100, 100}, "apple orange fruit banana peel");
    text.setColor(sf::Color::Red);
    text.setCharSize(20);

    text.setRows(200);
    text.setOutline(2, sf::Color::White);

    text.startRollOut(15, windowPtr->getDeltaTimePtr());
}


