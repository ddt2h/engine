#include "Window.hpp"

Engine::Window::Window() :  Engine::Window({1920, 1080},"Engine Window"){

}

Engine::Window::Window(sf::Vector2u size, const std::string& name) {
    this->window.create(sf::VideoMode(size.x, size.y), name);
    this->window.setKeyRepeatEnabled(false);
    this->defaultFont.loadFromFile("C:/Windows/Fonts/arial.ttf");
    //this->window.setFramerateLimit(5);
    deltaClock.restart();
}

void Engine::Window::drawEverything() {
    updateDeltaTime();
    pollEvents();
    window.clear();

}

sf::Font* Engine::Window::getFontPtr()
{
    return &defaultFont;
}

void Engine::Window::finishDrawing() {
    window.display();
}

sf::RenderWindow* Engine::Window::getWindowPtr() {
    return &window;
}

void Engine::Window::pollEvents() {
    event = sf::Event();
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

    }
}

sf::Event *Engine::Window::getLatestEvent() {
    return &this->event;
}

void Engine::Window::updateDeltaTime() {
    deltaTime = deltaClock.getElapsedTime().asSeconds();
    deltaClock.restart();
}

double *Engine::Window::getDeltaTimePtr() {
    return &this->deltaTime;
}

void Engine::Window::setWindowSize(sf::Vector2u size) {
    this->window.setSize(size);
}

sf::Vector2u Engine::Window::getWindowSize() {
    return this->window.getSize();
}
