#ifndef NFFSMODULE_HUDBAR_HPP
#define NFFSMODULE_HUDBAR_HPP

#include "SFML/Graphics.hpp"

#include <iostream>

class HUDBar{
public:
    HUDBar() = default;

    void init(sf::Vector2f positionCenter, float width, sf::Color color, int initialValue);

    void draw(sf::RenderWindow &win);

    void updateValues(int value);

    void addDelta(double *ptr);

private:
    sf::RectangleShape bar_;

    float width_;

    double *deltaPtr;

    int referenceValue{};

    double defValue{};
};

#endif //NFFSMODULE_HUDBAR_HPP
