#include "Binder.hpp"

void Binder::addBindButton(sf::Keyboard::Key pressKey, int emulateKey, int delayMs)
{
	this->pressKey = pressKey;
	this->emulateKey = emulateKey;
	this->delayMs = delayMs;
}

void Binder::run()
{
	std::thread impl(&Binder::runImpl, this);
	impl.detach();
}

void Binder::runImpl()
{
	Engine::SingleInput input;
	for (;;) {
		
		if (input.onClick(pressKey)) {
			Engine::Emulation::holdKeyboardKey(emulateKey);
			Sleep(delayMs);
			Engine::Emulation::releaseKeyboardKey(emulateKey);
		}
	}
}
