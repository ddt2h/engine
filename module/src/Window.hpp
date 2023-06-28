#ifndef NFFSMODULE_WINDOW_HPP
#define NFFSMODULE_WINDOW_HPP
#include <SFML/Graphics.hpp>
namespace Engine{

    class Window
    {
    private:
        sf::RenderWindow window;
    public:
        Window();

        Window(sf::Vector2u size, const std::string& name);

        void drawEverything();

        void finishDrawing();

        sf::RenderWindow* getWindowPtr();
    };
}

#endif //NFFSMODULE_WINDOW_HPP
