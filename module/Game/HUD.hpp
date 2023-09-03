#ifndef NFFSMODULE_HUD_HPP
#define NFFSMODULE_HUD_HPP

#include "HUDBar.hpp"

class HUD{
public:
    HUD() = default;

    void initValues(double *valHp, double *valSt, sf::RenderWindow *win);

    void draw(sf::RenderWindow &window);

    void addDelta(double *ptr);

private:
    HUDBar hpbar;
    HUDBar stbar;

    double *valueHP;
    double *valueST;
};

#endif //NFFSMODULE_HUD_HPP
