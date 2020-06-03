#include "Timer.h"

// Constructor
Timer::Timer()
{
    text.setFillColor(sf::Color::Red);
}

// Giving class access to the window
void Timer::setWindowPtr(sf::RenderWindow* windowPtr)
{
    window = windowPtr;
}

// Giving class access to the player
void Timer::setPlayerPtr(Player* playerPtr)
{
    player = playerPtr;
}

// Measuring time
void Timer::drawTime(sf::Font font)
{
    // If player is alive time is measured, otherwise timer stops
    if (player->isAlive())
    {
        seconds = int(time.getElapsedTime().asSeconds());
        miliseconds = int(time.getElapsedTime().asMilliseconds());
        if (seconds == 60)
        {
            seconds = 0;
            minutes++;
            time.restart();
        }
        if (seconds < 10)
            timer = std::to_string(minutes) + ":" + "0" + std::to_string(seconds);
        else
            timer = std::to_string(minutes) + ":" + std::to_string(seconds);
    }
    text.setFont(font);
    text.setString(timer);
    window->draw(text);
}
