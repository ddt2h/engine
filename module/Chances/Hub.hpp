#ifndef HUB_HPP
#define HUB_HPP

#include "../src/Window.hpp"
#include "../src/Data.hpp"
#include "../src/Text.hpp"
#include "../src/Timer.hpp"

#include "../GUI/Button.hpp"

#include "../src/WindowsSelect.hpp"


class Hub {
public:
	Hub() = default;

	void init(Engine::Window* winPtr, Engine::Data* dataPtr);

	void drawTo();

private:
	Engine::Window *winPtr;
	Engine::Data *dataPtr;

	//
	Engine::Timer timer;

	//
	Engine::Text timeText;

	//
	Button button;

};

#endif