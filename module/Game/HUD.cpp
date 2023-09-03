#include "HUD.hpp"

void HUD::initValues(double *valHp, double *valSt, sf::RenderWindow *win) {
    this->valueHP = valHp;
    this->valueST = valSt;

    hpbar.init({(float)win->getSize().x / 2, (float)win->getSize().y - 150},
               win->getSize().x / 2, sf::Color(240, 45, 45, 135), (int)*valHp);

    stbar.init({(float)win->getSize().x / 2, (float)win->getSize().y - 120},
               win->getSize().x / 3, sf::Color(25, 167, 25, 135), (int)*valSt);
}

void HUD::draw(sf::RenderWindow &window) {
    hpbar.updateValues(*valueHP);
    stbar.updateValues(*valueST);

    hpbar.draw(window);
    stbar.draw(window);
}

void HUD::addDelta(double *ptr) {
    this->hpbar.addDelta(ptr);
    this->stbar.addDelta(ptr);
}
