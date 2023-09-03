#include "Hub.hpp"

void Hub::init(Engine::Window* winPtr, Engine::Data* dataPtr)
{
	this->winPtr = winPtr;
	this->dataPtr = dataPtr;

	//
	timeText.setRows(200);
	timeText.init(winPtr->getWindowPtr(), dataPtr->getFont("arial.ttf"), { 5, 5 }, "time");
	timeText.setCharSize(30);
	timeText.setColor(sf::Color::White); 
	timeText.setBackgroundColor(sf::Color(100, 100, 100, 100));

	//
	button.create(winPtr);
	button.setSize({ 120, 30 });
	button.setText("Select File");
	button.setPosition({ 200, 200 });

}

void Hub::drawTo()
{
	//
	if (button.isClicked())
		Engine::getFilePath();

	//
	timeText.setFastString("Time passed: " + std::to_string(timer.secondsPassed()));
	timeText.drawTo();

	//
	button.drawTo();
}
