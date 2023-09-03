#ifndef NFFSMODULE_DUMMYOBJECT_HPP
#define NFFSMODULE_DUMMYOBJECT_HPP

#include "AbstractEngineObject.hpp"

#include "Drawing.hpp"
#include "Text.hpp"

class DummyObject : public AbstractEngineObject{
public:
    DummyObject();

    void draw() override;

private:
    Engine::Drawing drawing;
    Engine::Text text;

    void processEventsImpl() override;

    void createImpl(Engine::Window *windowPtr,  Engine::Data *dataPtr) override;

    void updateImpl() override;
};

#endif //NFFSMODULE_DUMMYOBJECT_HPP
