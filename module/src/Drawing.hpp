#ifndef NFFSMODULE_DRAWING_HPP
#define NFFSMODULE_DRAWING_HPP

#include <SFML/Graphics.hpp>

class Drawing{
public:
    Drawing();

    Drawing(sf::Texture *texture);

    void loadTexture(sf::Texture *texture);

    void setPosition(sf::Vector2i vec);

    void moveBy(sf::Vector2i vec);

    void resizeTo(sf::Vector2i vec);

    void setRenderRect(sf::Vector2i start, sf::Vector2i end);

    void rotateBy(int degree);

    void setTransparency(unsigned char alpha);

    void drawTo(sf::RenderWindow &window);

    void setVisible(bool isVisible);

    void setAlign(Drawing& drawing, std::string side);

    void setOutline(int width, sf::Color color);

private:
    sf::Sprite sprite_;

    unsigned char alpha_{255};

    bool isVisible_{true};

    int currentRotation{0};

    sf::Vector2i currentSize{0, 0};

    sf::Vector2i currentPosition{0, 0};
};

#endif //NFFSMODULE_DRAWING_HPP
