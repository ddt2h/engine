#ifndef NFFSMODULE_ENTITY_HPP
#define NFFSMODULE_ENTITY_HPP

#include "Drawing.hpp"

#include "Text.hpp"

struct CollisionStruct{
    int x, y, x1, y1;
};

//Abstract class
namespace Engine{

    class Entity{
    public:
        Entity();

        bool isColliding(Engine::Entity &entity);

    private:
        Engine::Drawing drawing;

        Engine::Text text;

        sf::RenderWindow *window;

        sf::Vector2u size{};

        sf::Vector2f position{};

        unsigned int weight{};

        CollisionStruct collisionStruct{};

    };
}

#endif //NFFSMODULE_ENTITY_HPP
