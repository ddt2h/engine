#ifndef BINDER_HPP
#define BINDER_HPP

#include "../src/Emulation.hpp"
#include "../src/SingleInput.hpp"

class Binder {
public:
	Binder() = default;

	void addBindButton(sf::Keyboard::Key pressKey, int emulateKey, int delayMs = 5);

	void run();

private:
	void runImpl();

	sf::Keyboard::Key pressKey{sf::Keyboard::Key::Unknown};
	int emulateKey{0};
	int delayMs{0};
};

#endif // !BINDER_HPP
