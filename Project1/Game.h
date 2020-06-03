/*
    Class which contains everything that should be put in the game loop:
    - it is drawing objects on the screen,
    - it uses other classes methods (Player.h, Enemies.h, Background.h, Timer.h) to make the game work 
*/

#pragma once
#include "Background.h"
#include "Enemies.h"
#include "Timer.h"

#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>

class Game
{
private:
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    Player player;
    Background background;
    Enemies enemies;
    Timer timer;

    void initWindow();
public:
    Game();
    ~Game();
    const bool running() const;
    void pollEvents();
    void update();
    void render(sf::Texture _background, sf::Texture square, sf::Texture enemy, sf::Font font);
    sf::RenderWindow* getWindow();
    void input();
};