#ifndef NFFSMODULE_TEXT_HPP
#define NFFSMODULE_TEXT_HPP
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Engine {

    class Text{
    public:
        Text();

        void init(sf::RenderWindow *winPtr, sf::Font *font = nullptr, sf::Vector2f position = {0, 0},
                  std::string value = "Default");

        void setFont(sf::Font *font);

        void setCharSize(int charSize);

        void setPosition(sf::Vector2f position);

        void setString(std::string string);

        void setFastString(std::string string);

        void setColor(sf::Color color);

        void moveBy(sf::Vector2f vec);

        void setOutline(int width, sf::Color color);

        void setCentration();

        void startRollOut(double rollSpeed, double *deltaPtr);

        void setRows(unsigned int rowWidth);

        void setBackgroundColor(sf::Color color);

        std::string getString();

        sf::Vector2f getPosition();

        sf::Vector2u getSize();

        void drawTo();

    private:
        sf::RenderWindow *winPtr;

        sf::Font *fontPtr{};

        std::vector<sf::Text> textWords;
        sf::Color color{sf::Color::Red};

        std::vector<std::string> words;
        void splitToWords();

        std::string value{};
        std::string drawString{};

        int charSize{12};
        bool isRolling{false};

        sf::RectangleShape outline;

        sf::Vector2f position{};

        sf::Vector2u size{};
        unsigned int borderWidth{100};

        double rollSpeed{};
        double currentRollPosition{};
        double *deltaPtr;
        int currentTextInstance{};

        void updateRollOut();
    };


}

#endif //NFFSMODULE_TEXT_HPP
