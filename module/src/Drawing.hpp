#ifndef NFFSMODULE_DRAWING_HPP
#define NFFSMODULE_DRAWING_HPP

#include <SFML/Graphics.hpp>

namespace Engine{

    class Drawing{
    public:
        Drawing();

        Drawing(sf::Texture *texture, sf::RenderWindow *winPtr);

        void initialize(sf::Texture *texture, sf::RenderWindow *winPtr);

        void initialize(sf::Vector2f size, sf::RenderWindow* winPtr);

        void loadTexture(sf::Texture *texture);

        void setPosition(sf::Vector2f vec);

        void moveBy(sf::Vector2f vec);

        void resizeTo(sf::Vector2u vec);

        void rescaleTo(sf::Vector2f vec);

        void setCentration();

        void setColor(sf::Color newColor);

        void setBackgroundColor(sf::Color newColor);

        void setRenderRect(sf::Vector2i start, sf::Vector2i end);

        void rotateBy(double degree);

        void setRotation(double degree);

        void setTransparency(unsigned char alpha);

        void drawTo();

        void setShader(sf::Shader *shader);

        void setShaderUniform(const std::string& uniform, float value);

        void setSpriteSheet(sf::Vector2u size);

        void nextSpriteSheetAnimation();

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

        bool isSpriteSheet{false};

        bool isShadered{false};

        int currentRotation{0};

        unsigned int currentSheetIDX{0};

        unsigned int currentSheetIDY{0};

        sf::Vector2u spriteSheetSingleSize{};

        sf::Vector2u currentSize{0, 0};

        sf::Vector2f currentPosition{0, 0};

        sf::RectangleShape outline;

        sf::Shader *shader_;
    };
}



#endif //NFFSMODULE_DRAWING_HPP
