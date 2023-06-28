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
    if (isVisible_){
        winPtr_->draw(this->sprite_);
        winPtr_->draw(this->outline);
    }
}

void Engine::Drawing::setPosition(sf::Vector2f vec) {
    sprite_.setPosition(vec);
    outline.setPosition(vec);
    this->currentPosition = vec;
}

void Engine::Drawing::moveBy(sf::Vector2f vec) {
    setPosition(currentPosition + vec);
    this->currentPosition = currentPosition + vec;
}

void Engine::Drawing::resizeTo(sf::Vector2u vec) {
    sprite_.setScale((float)vec.x / (float)currentSize.x, (float)vec.y / (float)currentSize.y);
    this->currentSize = vec;
}

void Engine::Drawing::setTransparency(unsigned char alpha) {
    sprite_.setColor(sf::Color(255, 255, 255, alpha));
    this->alpha_ = alpha;
}

void Engine::Drawing::setVisible(bool isVisible) {
    this->isVisible_ = isVisible;
}

void Engine::Drawing::rotateBy(int degree) {
    this->sprite_.rotate((float)degree);
    this->currentRotation += degree;
}

void Engine::Drawing::setOutline(int width, sf::Color color) {
    outline.setFillColor(sf::Color::Transparent);
    outline.setOutlineColor(color);
    outline.setOutlineThickness(width);
    outline.setSize({(float)currentSize.x, (float)currentSize.y});
}
//Add ratio
void Engine::Drawing::setAlign(Engine::Drawing &drawing, int side) {
    switch (side) {
        case 0:
            setPosition({drawing.getPosition().x - (float)drawing.getSize().x, drawing.getPosition().y });
            break;
        case 1:
            setPosition({drawing.getPosition().x + (float)drawing.getSize().x, drawing.getPosition().y });
            break;
        case 2:
            setPosition({drawing.getPosition().x, drawing.getPosition().y - (float)drawing.getSize().y });
            break;
        case 3:
            setPosition({drawing.getPosition().x, drawing.getPosition().y + (float)drawing.getSize().y });
            break;
        default:
            setPosition(drawing.getPosition());
            break;
    }
}

sf::Vector2f Engine::Drawing::getPosition() {
    return this->currentPosition;
}

sf::Vector2u Engine::Drawing::getSize() {
    return this->currentSize;
}


