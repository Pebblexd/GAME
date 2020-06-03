
/*
	Class which contains everything about enemies: 
	- drawing them (randomizing their position everytime they disappear; more enemies appear on the screen as time flows), 
	- their movement (they get faster as time flows; they move to different directions depending on the wall they were drew on),
	- collision with player (when player collides with enemy game and time stop)
*/
#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System/Time.hpp>
#include<array>
#include <random>
#include <functional>
#include <chrono>
#include "Player.h"

class Enemies
{
	sf::RenderWindow* window;
	Player* player;
	std::array<sf::Sprite, 20> enemies;
	sf::Vector2f enemyPosition;
	float velocity = 3;
	float velocityChange;
	float maxVelocity = 7;
	sf::Clock clock;
	int maxEnemies = 0;
	float time = 0;
public:
	void setWindowPtr(sf::RenderWindow* windowPtr);
	void setPlayerPtr(Player* playerPtr);
	void drawEnemies(sf::Texture texture);
	void moveEnemies();
	void setStartingPosition(sf::Sprite& enemy);
	void checkCollision(sf::Sprite _player, sf::Sprite _enemy);
	Enemies();
};

