#include "Window.hpp"

Engine::Window::Window() :  Engine::Window({800, 600},"Engine Window"){

}

Engine::Window::Window(sf::Vector2u size, const std::string& name) {
    this->window.create(sf::VideoMode(size.x, size.y), name);
}

void Engine::Window::drawEverything() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    window.clear();
}

void Engine::Window::finishDrawing() {
    window.display();
}

sf::RenderWindow* Engine::Window::getWindowPtr() {
    return &window;
}