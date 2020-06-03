
/*
    Class which contains everything about player: 
    - drawing him, 
    - his movement, 
    - checking if he is alive
*/

#pragma once
#include <SFML/Graphics.hpp>
class Player
{
private:
    sf::RenderWindow* window;
    sf::Sprite square;
    float velocityChangeLeft;
    float velocityChangeUp;
    float velocityChangeRight;
    float velocityChangeDown;
    bool alive = true;
public:
    void setWindowPtr(sf::RenderWindow* windowPtr);
    Player();
    void drawSquare(sf::Texture _ball);
    void moveSquare();
    sf::Sprite getSprite();
    bool isAlive();
    void kill();
};

