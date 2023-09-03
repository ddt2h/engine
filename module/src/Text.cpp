#include "Text.hpp"

Engine::Text::Text() { //moving is process intensive...

}

void Engine::Text::setPosition(sf::Vector2f position) {
    this->position = position;
    setString(value);
}

void Engine::Text::moveBy(sf::Vector2f vec) {
    this->position += vec;
    setString(value);
}

void Engine::Text::setFont(sf::Font *font) {
    if (font == nullptr){
        return;
    }
    

    this->fontPtr = font;


    for (int i = 0; i < textWords.size(); i++)
        textWords[i].setFont(*fontPtr);


   // this->size = {(unsigned int)text.getGlobalBounds().width, (unsigned int)text.getGlobalBounds().height};
}

void Engine::Text::splitToWords()
{
    size_t pos = value.find( ' ' );
    size_t initialPos = 0;
    words.clear();
    textWords.clear();

    while( pos != std::string::npos ) {
        words.push_back( value.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = value.find( ' ', initialPos );
    }

    words.push_back( value.substr( initialPos, std::min( pos, value.size() ) - initialPos + 1 ) );

}

void Engine::Text::setString(std::string string) {
    if (string.empty())
        return;

    this->value = string;
    this->drawString = this->value;

    splitToWords();

    sf::Vector2f latestPosition{getPosition().x, getPosition().y};

    int latestWidth = 0;
    int height = charSize;

    for (int i = 0; i < words.size(); i++){

        sf::Text word;
        word.setString(words[i]);
        word.setCharacterSize(charSize);
        word.setFont(*fontPtr);
        word.setPosition(latestPosition.x + latestWidth, latestPosition.y);

        word.setFillColor(this->color);

        latestPosition.x = word.getPosition().x + word.getGlobalBounds().width + charSize / 2;

        if (word.getGlobalBounds().width + latestPosition.x > borderWidth + position.x && i != 0){
            latestPosition.y += charSize;
            latestPosition.x = getPosition().x;
            word.setPosition(latestPosition.x + latestWidth, latestPosition.y);
            latestPosition.x = word.getPosition().x + word.getGlobalBounds().width + charSize / 2;
            height += word.getGlobalBounds().height + charSize / 2;
        }
        textWords.push_back(word);

    }

    this->size = {borderWidth, (unsigned int)height} ;
}

void Engine::Text::setFastString(std::string string) {

    if (textWords.size() > 1){
        for (int i = 0; i < textWords.size(); i++){
            if (i != 0)
                textWords.pop_back();
        }
    }

    textWords[0].setString(string);

    size = {(unsigned int)textWords[0].getGlobalBounds().width,
            (unsigned int)textWords[0].getGlobalBounds().height + charSize / 2};
    outline.setSize({(float)size.x, (float)size.y});


}

void Engine::Text::setColor(sf::Color color) {
    for (int i = 0; i < textWords.size(); i++)
        textWords[i].setFillColor(color);

    this->color = color;
}

sf::Vector2f Engine::Text::getPosition() {
    return this->position;
}

sf::Vector2u Engine::Text::getSize() {
    return this->size;
}

void Engine::Text::setOutline(int width, sf::Color color) {
    outline.setFillColor(sf::Color::Transparent);
    outline.setOutlineColor(color);
    outline.setOutlineThickness(width);
    outline.setSize({(float)size.x, (float)size.y});
}

void Engine::Text::setCentration()
{
    //Not working
   /* for (int i = 0; i < textWords.size(); i++) {
        textWords[i].setOrigin(textWords[i].getGlobalBounds().width / 2, textWords[i].getGlobalBounds().height / 2);
    }*/
    
}

void Engine::Text::drawTo() {
    if (textWords.empty())
        return;

    updateRollOut();
    for (int i = 0; i < textWords.size(); i++)
        this->winPtr->draw(textWords[i]);

    outline.setPosition(position);
    this->winPtr->draw(this->outline);
}

void Engine::Text::startRollOut(double rollSpeed, double *deltaPtr) {
    this->deltaPtr = deltaPtr;
    this->rollSpeed = rollSpeed;
    this->isRolling = true;
    this->currentTextInstance = 0;
    currentRollPosition = 0;

    for (int i = 0; i < textWords.size(); i++){
        textWords[i].setString("");
    }
}

void Engine::Text::updateRollOut() {

    if (!isRolling)
        return;

    static double currentChar = 0;

    if (textWords.empty() || currentTextInstance > words.size() - 1)
        return;

    std::string currentWord = words[currentTextInstance].substr(0, (int)currentChar);
    textWords[currentTextInstance].setString(currentWord);

    currentChar += rollSpeed * *deltaPtr;

    if (currentChar >= words[currentTextInstance].size() + 1){
        currentChar = 0;
        currentTextInstance++;

    }

}

void Engine::Text::setCharSize(int charSize) {
    this->charSize = charSize;
    setString(this->value);
}

void Engine::Text::setRows(unsigned int rowWidth) {
    borderWidth = rowWidth;
    setString(this->value);
}

void Engine::Text::init(sf::RenderWindow *winPtr, sf::Font *font, sf::Vector2f position, std::string value) {
    this->winPtr = winPtr;
    setFont(font);
    setString(value);
    setPosition(position);

}

void Engine::Text::setBackgroundColor(sf::Color color) {
    outline.setFillColor(color);
    outline.setSize({(float)size.x, (float)size.y});
}

std::string Engine::Text::getString()
{
    return value;
}




