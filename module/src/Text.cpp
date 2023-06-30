#include "Text.hpp"

Engine::Text::Text() {

}

Engine::Text::Text(sf::RenderWindow *winPtr, sf::Font *font, sf::Vector2f position, std::string value) {
    setFont(font);
    setPosition(position);
    setString(value);

    this->winPtr = winPtr;
}

void Engine::Text::setPosition(sf::Vector2f position) {
    this->position = position;
    text.setPosition(position);
}

void Engine::Text::moveBy(sf::Vector2f vec) {
    this->position += vec;
    text.move(vec);
}

void Engine::Text::setFont(sf::Font *font) {
    if (font == nullptr) { this->fontPtr->loadFromFile("C:/Windows/Fonts/arial.ttf"); }
    else
        this->fontPtr = font;

    text.setFont(*fontPtr);

    this->size = {(unsigned int)text.getGlobalBounds().width, (unsigned int)text.getGlobalBounds().height};
}

void Engine::Text::setString(std::string string) {
    this->value = string;
    text.setString(value);

    this->size = {(unsigned int)text.getGlobalBounds().width, (unsigned int)text.getGlobalBounds().height};
}

void Engine::Text::setColor(sf::Color color) {
    text.setFillColor(color);
}

sf::Vector2f Engine::Text::getPosition() {
    return this->position;
}

sf::Vector2u Engine::Text::getSize() {
    return this->size;
}

void Engine::Text::drawTo() {
    this->winPtr->draw(text);
}
