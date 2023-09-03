#ifndef NFFSMODULE_WINDOW_HPP
#define NFFSMODULE_WINDOW_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
namespace Engine{

    class Window
    {
    private:
        sf::RenderWindow window;

        void pollEvents();

        sf::Event event;

        sf::Clock deltaClock{};

        sf::Font defaultFont{};

        double deltaTime{};

        void updateDeltaTime();
    public:
        Window();

        Window(sf::Vector2u size, const std::string& name);

        void drawEverything();

        sf::Font* getFontPtr();

        void finishDrawing();

        void setWindowSize(sf::Vector2u size);

        sf::Vector2u getWindowSize();

        double *getDeltaTimePtr();

        sf::Event* getLatestEvent();

        sf::RenderWindow* getWindowPtr();
    };
}

#endif //NFFSMODULE_WINDOW_HPP
