#ifndef SINGLE_INPUT_HPP
#define SINGLE_INPUT_HPP

#include "SFML/Window/Keyboard.hpp"

namespace Engine {
	class SingleInput {
	public:
		SingleInput() = default;

		bool onClick(sf::Keyboard::Key key);

	private:
		bool locked_{ false };
	};
}

#endif