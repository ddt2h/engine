#include "Drawing.hpp"

Drawing::Drawing() {

}

void Drawing::loadTexture(sf::Texture *texture) {
    sprite_.setTexture(*texture);
}

Drawing::Drawing(sf::Texture *texture) {
    loadTexture(texture);
}