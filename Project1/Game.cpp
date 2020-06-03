#include "Game.h"

// Initializing window
void Game::initWindow()
{
    videoMode.width = 1280;
    videoMode.height = 720;

    window = new sf::RenderWindow(this->videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
}

// Constructor
Game::Game()
{
    //initVariables();
    initWindow();
    player.setWindowPtr(window);
    enemies.setPlayerPtr(&player);
    background.setWindowPtr(window);
    timer.setWindowPtr(window);
    timer.setPlayerPtr(&player);
    enemies.setWindowPtr(window);
}

// Destructor
Game::~Game()
{
    delete window;
}

// Checking if game is still running
const bool Game::running() const
{
    return window->isOpen();
}

// Event polling
void Game::pollEvents()
{
    while (window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        }
    }
}

// Inputs
void Game::input()
{
    player.moveSquare();
}

// Updating the game
void Game::update()
{
    pollEvents();
}

// Rendering objects on the screen
void Game::render(sf::Texture _background, sf::Texture square, sf::Texture enemy, sf::Font font)
{
    window->clear();
    background.drawBackground(_background);

    player.drawSquare(square);
    enemies.drawEnemies(enemy);
    enemies.moveEnemies();
    timer.drawTime(font);

    // Drawing game objects
    window->display();
}

// Window getter used for giving access to the window to other classes
sf::RenderWindow* Game::getWindow()
{
    return window;
}