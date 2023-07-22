#ifndef NFFSMODULE_TEXT_HPP
#define NFFSMODULE_TEXT_HPP
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Engine {

    class Text{
    public:
        Text();

        Text(sf::RenderWindow *winPtr, sf::Font *font = nullptr, sf::Vector2f position = {0, 0},
             std::string value = "Default");

        void setFont(sf::Font *font);

        void setPosition(sf::Vector2f position);

        void setString(std::string string);

        void setColor(sf::Color color);

        void moveBy(sf::Vector2f vec);

        sf::Vector2f getPosition();

        sf::Vector2u getSize();

        void drawTo();

    private:
        sf::RenderWindow *winPtr;

        sf::Font *fontPtr{};

        sf::Text text;

        std::string value{};

        sf::Vector2f position{};

        sf::Vector2u size{};
    };


}

#endif //NFFSMODULE_TEXT_HPP
