#ifndef NFFSMODULE_COLLISIONHANDLER_HPP
#define NFFSMODULE_COLLISIONHANDLER_HPP

#include <vector>
#include "SFML/Graphics.hpp"

namespace Engine{
    class CollisionHandler{
    public:
        CollisionHandler() = default;

        bool isColliding(Engine::CollisionHandler &collisionHandler);

        void addPlane(std::pair<sf::Vector2f, sf::Vector2f> plane);

        std::vector<std::pair<sf::Vector2f, sf::Vector2f>> getPlanes();

        void setPlane(int id, std::pair<sf::Vector2f, sf::Vector2f> value);

    private:
        std::vector<std::pair<sf::Vector2f, sf::Vector2f>> planes;

        bool resolveIntersection(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c, sf::Vector2f d);
    };
}

#endif //NFFSMODULE_COLLISIONHANDLER_HPP
