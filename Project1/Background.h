/*
	Class which draws background
*/

#pragma once
#include <SFML/Graphics.hpp>
class Background
{
	sf::RenderWindow* window;
	sf::Sprite background;
public:
	void setWindowPtr(sf::RenderWindow* windowPtr);
	void drawBackground(sf::Texture texture);
};

