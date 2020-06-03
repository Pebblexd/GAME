/*
	Class which measures how much time player did survive and displays it on the screen
*/

#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include "Player.h"
class Timer
{
	sf::RenderWindow* window;
	int minutes = 0;
	int seconds = 0;
	int miliseconds = 0;
	sf::Clock time;
	std::string timer;
	sf::Text text;
	Player* player;
public:
	void setWindowPtr(sf::RenderWindow* windowPtr);
	void setPlayerPtr(Player* playerPtr);
	void drawTime(sf::Font font);
	Timer();
};

