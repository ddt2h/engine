#include "SingleInput.hpp"

bool Engine::SingleInput::onClick(sf::Keyboard::Key key)
{
	bool ret = false;
	if (sf::Keyboard::isKeyPressed(key) && !locked_) {
		locked_ = true;
		ret = true;
	}
	if (!sf::Keyboard::isKeyPressed(key)) {
		locked_ = false;
		ret = false;
	}
	return ret;
}
