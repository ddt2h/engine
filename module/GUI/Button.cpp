#include "Button.hpp"

void Button::setText(std::string text)
{
	text_.setString(text);
}

bool Button::isClicked()
{
	if (clicked_) {
		clicked_ = false;
		return true;
	}
	return false;
	
}

void Button::setPositionImpl(sf::Vector2f newPos)
{
	cell_.setPosition(newPos);
	text_.setPosition(newPos);
}

void Button::drawToImpl()
{
	update();

	cell_.drawTo();
	text_.drawTo();
}

void Button::createImpl(Engine::Window* winPtr)
{
	cell_.initialize({ 1, 1 }, winPtr->getWindowPtr());
	cell_.setOutline(1, this->outLineColor);

	text_.init(winPtr->getWindowPtr(), winPtr->getFontPtr());
	text_.setColor(this->textColor);
	text_.setCharSize(textSize);
	text_.setRows(999);

	updateDimensions();
}

void Button::setVisibleImpl(bool visible)
{

}

void Button::updateDimensionsImpl()
{
	this->dimensions = cell_.getSize();
}

void Button::setSizeImpl(sf::Vector2u newSize)
{
	cell_.resizeTo(newSize);
	updateDimensions();
}

void Button::onHoverImpl()
{
	cell_.setBackgroundColor(this->hoverCellColor);
	cell_.setOutline(1, this->outLineColor);
}

void Button::onNotHoverImpl()
{
	cell_.setBackgroundColor(this->notHoverCellColor);
	cell_.setOutline(1, this->notHoverCellColor);
}

void Button::onClickImpl()
{
	clicked_ = true;
}

void Button::onMouseHoldingImpl()
{
	cell_.setBackgroundColor(this->pressingColor);
}
