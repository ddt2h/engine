#include "Drawing.hpp"

Engine::Drawing::Drawing() {

}

void Engine::Drawing::loadTexture(sf::Texture *texture)  {
    sprite_.setTexture(*texture);
    currentSize = texture->getSize();
}

Engine::Drawing::Drawing(sf::Texture *texture, sf::RenderWindow *winPtr) : winPtr_(winPtr) {
    if (texture != nullptr)
        loadTexture(texture);
}

void Engine::Drawing::drawTo() {
    winPtr_->draw(this->sprite_);
}

void Engine::Drawing::setPosition(sf::Vector2f vec) {
    this->currentPosition = vec;
    sprite_.setPosition(currentPosition);
}

void Engine::Drawing::resizeTo(sf::Vector2u vec) {
    sprite_.setScale((float)vec.x / (float)currentSize.x, (float)vec.y / (float)currentSize.y);
    this->currentSize = vec;
}
