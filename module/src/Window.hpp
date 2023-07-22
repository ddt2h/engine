#ifndef NFFSMODULE_WINDOW_HPP
#define NFFSMODULE_WINDOW_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
namespace Engine{

    class Window
    {
    private:
        sf::RenderWindow window;

        void pollEvents();

        sf::Event event;
    public:
        Window();

        Window(sf::Vector2u size, const std::string& name);

        void drawEverything();

        void finishDrawing();

        sf::Event* getLatestEvent();

        sf::RenderWindow* getWindowPtr();
    };
}

#endif //NFFSMODULE_WINDOW_HPP
