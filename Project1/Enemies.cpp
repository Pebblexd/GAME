#include "Enemies.h"

// Giving class access to the window
void Enemies::setWindowPtr(sf::RenderWindow* windowPtr)
{
	window = windowPtr;
}

// Giving class access to the player
void Enemies::setPlayerPtr(Player* playerPtr)
{
	player = playerPtr;
}

// Constructor
Enemies::Enemies()
{
	for(int i = 0 ; i < 20 ; i++)
		setStartingPosition(enemies[i]);
}

// Randomizing enemy starting position
void Enemies::setStartingPosition(sf::Sprite& enemy)
{
	std::mt19937::result_type seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	auto dice_rand = std::bind(std::uniform_int_distribution<int>(1, 4), std::mt19937(seed));
	auto dice_randY = std::bind(std::uniform_int_distribution<int>(0, 670), std::mt19937(seed));
	auto dice_randX = std::bind(std::uniform_int_distribution<int>(0, 1230), std::mt19937(seed));
	int choice = dice_rand();
	switch (choice)
	{
		//left wall
		case 1:
		{
			int positionY = dice_randY();
			enemy.setPosition(-50, positionY);
			enemy.setRotation(90);
			break;
		}
		//top wall
		case 2:
		{
			int positionX = dice_randX();
			enemy.setPosition(positionX, -50);
			enemy.setRotation(180);
			break;
		}
		//right wall
		case 3:
		{
			int positionY = dice_randY();
			enemy.setPosition(1330, positionY);
			enemy.setRotation(270);
			break;
		}
		//bottom wall
		case 4:
		{
			int positionX = dice_randX();
			enemy.setPosition(positionX, 770);
			enemy.setRotation(0);
			break;
		}
	}
}

// Checking if enemy collides with player
void Enemies::checkCollision(sf::Sprite _player, sf::Sprite _enemy)
{
	// Stopping enemies and players movement
	if (_player.getGlobalBounds().intersects(_enemy.getGlobalBounds()))
	{
		velocityChange = 0;
		velocity = 0;
		maxVelocity = 0;
		player->kill();
	}
}

// Enemies movement which depends on the wall they were drew on
void Enemies::moveEnemies()
{
	for (int i = 0; i < 20; i++)
	{
		// Moving to the right
		if (enemies.at(i).getRotation() == 90 && enemies.at(i).getTexture() != nullptr)
		{
			if (velocityChange < velocity)
				velocityChange += 0.1f;
			enemies.at(i).move(sf::Vector2f(velocityChange, 0));

			enemyPosition = enemies.at(i).getPosition();
			if (enemyPosition.x > 1330)
			{
				setStartingPosition(enemies.at(i));
				if (velocity < maxVelocity)
					velocity += 0.05;
			}
			checkCollision(player->getSprite(), enemies.at(i));
		}
		// Moving to the bottom 
		else if (enemies.at(i).getRotation() == 180 && enemies.at(i).getTexture() != nullptr)
		{
			if (velocityChange < velocity)
				velocityChange += 0.1f;
			enemies.at(i).move(sf::Vector2f(0, velocityChange));

			enemyPosition = enemies.at(i).getPosition();
			if (enemyPosition.y > 720)
			{
				setStartingPosition(enemies.at(i));
				if (velocity < maxVelocity)
					velocity += 0.05;
			}
			checkCollision(player->getSprite(), enemies.at(i));
		}
		// Moving to the left
		else if (enemies.at(i).getRotation() == 270 && enemies.at(i).getTexture() != nullptr)
		{
			if (velocityChange < velocity)
				velocityChange += 0.1f;
			enemies.at(i).move(sf::Vector2f(-velocityChange, 0));

			enemyPosition = enemies.at(i).getPosition();
			if (enemyPosition.x < -50)
			{
				setStartingPosition(enemies.at(i));
				if (velocity < maxVelocity)
					velocity += 0.05;
			}
			checkCollision(player->getSprite(), enemies.at(i));
		}
		// Moving to the top
		else if(enemies.at(i).getTexture() != nullptr)
		{
			if (velocityChange < velocity)
				velocityChange += 0.1f;
			enemies.at(i).move(sf::Vector2f(0, -velocityChange));

			enemyPosition = enemies.at(i).getPosition();
			if (enemyPosition.y < -50)
			{
				setStartingPosition(enemies.at(i));
				if (velocity < maxVelocity)
					velocity += 0.05;
			}
			checkCollision(player->getSprite(), enemies.at(i));
		}
	}
}

// Drawing enemies
void Enemies::drawEnemies(sf::Texture texture)
{
	for (int i = 0; i <= maxEnemies; i++)
	{
		enemies.at(i).setTexture(texture);
		window->draw(enemies.at(i));
	}
	// As time flows more enemies appear on the screen
	time += clock.getElapsedTime().asSeconds();
	if (time > 600)
	{
		time = 0;
		if(maxEnemies <19)
			maxEnemies++;
		clock.restart();
	}
}
