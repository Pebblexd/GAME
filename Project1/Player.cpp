#include "Player.h"

// Giving class access to the window
void Player::setWindowPtr(sf::RenderWindow* windowPtr)
{
    window = windowPtr;
}

// Constructor
Player::Player()
{
    square.setPosition(605, 335);
}


// Drawing player
void Player::drawSquare(sf::Texture _ball)
{
    square.setTexture(_ball);
    window->draw(square);
}

// Player movement
void Player::moveSquare()
{
    if (this->isAlive())
    {
        // Moving to the left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (square.getPosition().x > 0)
            {
                if (velocityChangeLeft <= 10)
                    velocityChangeLeft += 0.75f;

                square.move(sf::Vector2f(-velocityChangeLeft, 0));
            }
        }
        else
        {
            velocityChangeLeft = 0;
        }

        // Moving to the top
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (square.getPosition().y > 0)
            {
                if (velocityChangeUp <= 10)
                    velocityChangeUp += 0.75f;

                square.move(sf::Vector2f(0, -velocityChangeUp));
            }
        }
        else
        {
            velocityChangeUp = 0;
        }

        // Moving to the right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (square.getPosition().x < (1280 - 50))
            {
                if (velocityChangeRight <= 10)
                    velocityChangeRight += 0.75f;

                square.move(sf::Vector2f(velocityChangeRight, 0));
            }
        }
        else
        {
            velocityChangeRight = 0;
        }

        // Moving to the bottom
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (square.getPosition().y < (720 - 50))
            {
                if (velocityChangeDown <= 10)
                    velocityChangeDown += 0.75f;

                square.move(sf::Vector2f(0, velocityChangeDown));
            }
        }
        else
        {
            velocityChangeDown = 0;
        }
    }
}

// Getter for players texture (used in Enemies.h class)
sf::Sprite Player::getSprite()
{
    return square;
}

// Checking if player is alive
bool Player::isAlive()
{
	return alive;
}

// Setting players death
void Player::kill()
{
    alive = false;
}
