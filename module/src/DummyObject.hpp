#ifndef NFFSMODULE_DUMMYOBJECT_HPP
#define NFFSMODULE_DUMMYOBJECT_HPP

#include "AbstractEngineObject.hpp"

#include "Drawing.hpp"

class DummyObject : public AbstractEngineObject{
public:
    DummyObject();

    void draw() override;

    void createImpl(sf::RenderWindow *windowPtr, Engine::Data *dataPtr, sf::Event *windowEventPtr) override;

private:
    Engine::Drawing drawing;

    void processEventsImpl() override;

    void updateImpl() override;
};

#endif //NFFSMODULE_DUMMYOBJECT_HPP
