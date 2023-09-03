#include "HUDBar.hpp"

void HUDBar::draw(sf::RenderWindow &win) {
    win.draw(bar_);
}

void HUDBar::updateValues(int value) {

    if (value == (int)defValue)
        defValue = value;

    defValue += (value - defValue) * *deltaPtr * 10;

    if (defValue <= 0){
        this->bar_.setSize({0, 0});
        return;
    }

    float scale =  defValue / (float)referenceValue;

    this->bar_.setSize({(float)width_ * scale, 20});
    this->bar_.setOrigin(((float)width_ * scale) / 2, 20 / 2);
}

void HUDBar::init(sf::Vector2f positionCenter, float width, sf::Color color, int initialValue) {
    this->bar_.setSize({width, 20});
    this->bar_.setFillColor(color);
    this->bar_.setOrigin(width/2, 20 / 2);
    this->bar_.setPosition(positionCenter);
    this->bar_.setOutlineThickness(3);
    this->bar_.setOutlineColor(sf::Color(color.r / 2, color.g / 2, color.b / 2, 50));

    this->width_ = width;

    this->referenceValue = initialValue;

}

void HUDBar::addDelta(double *ptr) {
    this->deltaPtr = ptr;
}
