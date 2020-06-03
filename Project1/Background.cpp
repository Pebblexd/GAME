#include "Background.h"

// Giving class access to the window
void Background::setWindowPtr(sf::RenderWindow* windowPtr)
{
    window = windowPtr;
}

// Drawing background
void Background::drawBackground(sf::Texture texture)
{
    background.setTexture(texture);
    window->draw(background);
}