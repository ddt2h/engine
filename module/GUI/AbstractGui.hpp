#ifndef AbsGuiHpp
#define AbsGuiHpp

#include "../src/Window.hpp"


class AbstractGui {
public:
	AbstractGui() = default;

	void create(Engine::Window *winPtr);

	void updateDimensions();

	void setPosition(sf::Vector2f newPos);

	void setSize(sf::Vector2u newSize);

	void setVisible(bool visible);

	void drawTo();

	void update();

protected:
	virtual void createImpl(Engine::Window* winPtr);
	virtual void updateDimensionsImpl();
	virtual void setPositionImpl(sf::Vector2f newPos);
	virtual void setSizeImpl(sf::Vector2u newSize);
	virtual void setVisibleImpl(bool visible);
	virtual void drawToImpl();

	//
	virtual void onHoverImpl();
	virtual void onNotHoverImpl();
	virtual void onClickImpl();
	virtual void onMouseHoldingImpl();

	Engine::Window* winPtr;

	sf::Vector2f position{};

	sf::Vector2u dimensions{};

	bool isVisible{true};

	bool isHovering();

private:
	
	
};

#endif // !AbsGuiHpp
