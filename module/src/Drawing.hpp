#ifndef NFFSMODULE_DRAWING_HPP
#define NFFSMODULE_DRAWING_HPP

#include <SFML/Graphics.hpp>

namespace Engine{

    class Drawing{
    public:
        Drawing();

        Drawing(sf::Texture *texture, sf::RenderWindow *winPtr);

        void loadTexture(sf::Texture *texture);

        void setPosition(sf::Vector2f vec);

        void moveBy(sf::Vector2f vec);

        void resizeTo(sf::Vector2u vec);

        void setRenderRect(sf::Vector2i start, sf::Vector2i end);

        void rotateBy(int degree);

        void setTransparency(unsigned char alpha);

        void drawTo();

        void setVisible(bool isVisible);

        void setAlign(Drawing& drawing, int side);

        void setOutline(int width, sf::Color color);

        sf::Vector2f getPosition();

        sf::Vector2u getSize();

    private:
        sf::RenderWindow *winPtr_;

        sf::Sprite sprite_;

        unsigned char alpha_{255};

        bool isVisible_{true};

        int currentRotation{0};

        sf::Vector2u currentSize{0, 0};

        sf::Vector2f currentPosition{0, 0};

        sf::RectangleShape outline;
    };
}



#endif //NFFSMODULE_DRAWING_HPP
