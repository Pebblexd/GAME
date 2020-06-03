#pragma once
#include <SFML/Graphics.hpp>
class Menu
{
	bool active = true;
	sf::RenderWindow* window;
public:
	void setWindowPtr(sf::RenderWindow* windowPtr);
	bool isActive();
	void deactivate();
};

