#ifndef NFFSMODULE_ABSTRACTENGINEOBJECT_HPP
#define NFFSMODULE_ABSTRACTENGINEOBJECT_HPP

#include <map>
#include <string>

#include "Window.hpp"

#include "Data.hpp"

class AbstractEngineObject{
public:
    AbstractEngineObject();

    void addState(std::string stateName, bool originalValue = false);

    bool getStateSingle(std::string stateName);

    bool getState(std::string stateName);

    void setState(std::string stateName, bool value);

    void resetState(std::string stateName);

    void invertState(std::string stateName);

    void create(Engine::Window *windowPtr,  Engine::Data *dataPtr);

    void update();

    void processEvents();

    virtual void createImpl(Engine::Window *windowPtr, Engine::Data *dataPtr);

    virtual void updateImpl();

    virtual void processEventsImpl();

    virtual void draw();

private:
    std::map<std::string, bool> states;

protected:
    sf::RenderWindow *windowPtr;

    double *deltaPtr;

    sf::Event *windowEventPtr;

    Engine::Data *dataPtr;
};

#endif //NFFSMODULE_ABSTRACTENGINEOBJECT_HPP
