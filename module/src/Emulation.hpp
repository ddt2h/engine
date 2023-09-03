#ifndef INPUT_HPP
#define INPUT_HPP

//For replication

#include "SFML/Graphics.hpp"

#include <dinput.h>
#include <thread>

//For debuggin

#include <iostream>

#include "SingleInput.hpp"

//Threaded implementation

namespace Engine {

	static class Emulation {

	public:
		Emulation() = default;

		//Mouse
		
		static void holdLeftMouseButton();

		static void holdRightMouseButton();

		static void releaseLeftMouseButton();

		static void releaseRightMouseButton();

		static void clickLeftMouseButton(int delayMs = 30);

		static void clickRightMouseButton(int delayMs = 30);

		//Scroll

		static void scroll(int value);

		//Keyboard

		static void holdKeyboardKey(int keyCode);

		static void releaseKeyboardKey(int keyCode);

		static void clickKeyboardKey(int keyCode, int delayMs = 30);

		//Mouse movement

		static void setMousePosition(int x, int y);

	private:

		//Impl

		static void clickLeftMouseButtonImpl(int delayMs);

		static void clickRightMouseButtonImpl(int delayMs);

		static void clickKeyboardKeyImpl(int keyCode, int delayMs);

	

	};

	
}


#endif // !INPUT_HPP
