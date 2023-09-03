#include "AbstractGui.hpp"

void AbstractGui::create(Engine::Window* winPtr)
{
	this->winPtr = winPtr;
	createImpl(winPtr);
}

void AbstractGui::updateDimensions()
{
	updateDimensionsImpl();
}

void AbstractGui::setPosition(sf::Vector2f newPos)
{
	this->position = newPos;
	setPositionImpl(newPos);
}

void AbstractGui::setSize(sf::Vector2u newSize)
{
	this->dimensions = newSize;
	setSizeImpl(newSize);
	updateDimensions();
}

void AbstractGui::setVisible(bool visible)
{
	this->isVisible = visible;
	setVisibleImpl(visible);
}

bool AbstractGui::isHovering()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*winPtr->getWindowPtr());

	return (mousePos.x > position.x && mousePos.y > position.y
		&& mousePos.x < position.x + dimensions.x && mousePos.y < position.y + dimensions.y);
}

void AbstractGui::drawTo()
{
	if (!isVisible)
		return;

	drawToImpl();
}

void AbstractGui::update()
{
	if (!winPtr->getWindowPtr()->hasFocus())
		return;

	if (isHovering()) {
		onHoverImpl();

		if (winPtr->getLatestEvent()->type == sf::Event::MouseButtonPressed)
			onClickImpl();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			onMouseHoldingImpl();
	}
	else
		onNotHoverImpl();
}

void AbstractGui::createImpl(Engine::Window* winPtr)
{

}

void AbstractGui::updateDimensionsImpl()
{

}

void AbstractGui::setPositionImpl(sf::Vector2f newPos)
{

}

void AbstractGui::setSizeImpl(sf::Vector2u newSize)
{

}

void AbstractGui::setVisibleImpl(bool visible)
{

}

void AbstractGui::drawToImpl()
{

}

void AbstractGui::onHoverImpl()
{

}

void AbstractGui::onNotHoverImpl()
{

}

void AbstractGui::onClickImpl()
{

}

void AbstractGui::onMouseHoldingImpl()
{

}
