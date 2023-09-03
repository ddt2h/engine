#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "AbstractGui.hpp"

#include "../src/Drawing.hpp"
#include "../src/Text.hpp"

class Button : public AbstractGui {
public:
	Button() = default;
	
	void setText(std::string text);

	bool isClicked();

protected:

	void setPositionImpl(sf::Vector2f newPos) override;

	void drawToImpl() override;

	void createImpl(Engine::Window* winPtr) override;

	void setVisibleImpl(bool visible) override;

	void updateDimensionsImpl() override;

	void setSizeImpl(sf::Vector2u newSize) override;

	//

	void onHoverImpl() override;

	void onNotHoverImpl() override;

	void onClickImpl() override;

	void onMouseHoldingImpl() override;


private:
	Engine::Drawing cell_;
	Engine::Text text_;

	sf::Color outLineColor{ 255, 255, 255, 255 };
	sf::Color hoverCellColor{155, 155, 155, 255};
	sf::Color notHoverCellColor{ 125, 125, 125, 255 };
	sf::Color textColor{ 255, 255, 255, 255 };
	sf::Color pressingColor{85, 85, 85, 255};

	unsigned int textSize{ 20 };

	bool clicked_{false};
};


#endif // !BUTTON_HPP
