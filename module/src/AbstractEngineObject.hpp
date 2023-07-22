#ifndef NFFSMODULE_ABSTRACTENGINEOBJECT_HPP
#define NFFSMODULE_ABSTRACTENGINEOBJECT_HPP

#include <map>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

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

    void create(sf::RenderWindow *windowPtr,  Engine::Data *dataPtr, sf::Event *windowEventPtr);

    void update();

    void processEvents();

    virtual void createImpl(sf::RenderWindow *windowPtr, Engine::Data *dataPtr, sf::Event *windowEventPtr);

    virtual void updateImpl();

    virtual void processEventsImpl();

    virtual void draw();

private:
    std::map<std::string, bool> states;

    Engine::Data *dataPtr;

protected:
    sf::RenderWindow *windowPtr;

    sf::Event *windowEventPtr;
};

#endif //NFFSMODULE_ABSTRACTENGINEOBJECT_HPP
