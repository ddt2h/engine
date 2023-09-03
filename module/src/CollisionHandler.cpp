#include "CollisionHandler.hpp"

bool Engine::CollisionHandler::isColliding(Engine::CollisionHandler &collisionHandler) {
    for (int i = 0; i < collisionHandler.getPlanes().size(); i++){
        for (int j = 0; j < planes.size(); j++){
            if (resolveIntersection(collisionHandler.getPlanes()[i].first, collisionHandler.getPlanes()[i].second,
                                    planes[j].first, planes[j].second))
                return true;
        }
    }
    return false;
}

bool Engine::CollisionHandler::resolveIntersection(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c, sf::Vector2f d) {
    float denominator = ((b.x - a.x) * (d.y - c.y)) - ((b.y - a.y) * (d.x - c.x));
    float numerator1 = ((a.y - c.y) * (d.x - c.x)) - ((a.x - c.x) * (d.y - c.y));
    float numerator2 = ((a.y - c.y) * (b.x - a.x)) - ((a.x - c.x) * (b.y - a.y));

    // Detect coincident lines (has a problem, read below)
    if (denominator == 0) return numerator1 == 0 && numerator2 == 0;

    float r = numerator1 / denominator;
    float s = numerator2 / denominator;

    return (r >= 0 && r <= 1) && (s >= 0 && s <= 1);
}

std::vector<std::pair<sf::Vector2f, sf::Vector2f>> Engine::CollisionHandler::getPlanes() {
    return planes;
}

void Engine::CollisionHandler::addPlane(std::pair<sf::Vector2f, sf::Vector2f> plane) {
    planes.push_back(plane);
}

void Engine::CollisionHandler::setPlane(int id, std::pair<sf::Vector2f, sf::Vector2f> value) {
    planes[id] = value;
}
