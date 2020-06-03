#include "Game.h"

int main()
{
    // Loading textures, font and music
    sf::Texture background;
    background.loadFromFile("Images/background.png");

    sf::Texture square;
    square.loadFromFile("Images/player.png");

    sf::Texture enemy;
    enemy.loadFromFile("Images/enemy.png");

    sf::Font font;
    font.loadFromFile("Fonts/alata-regular.ttf");

    sf::Music music;
    music.openFromFile("Sounds/Soliloquy.ogg");
    music.setVolume(1);
    music.setLoop(true);
    music.play();

    //FPS stabilisation mechanism
    const int FRAMES_PER_SECOND = 50;
    const int SKIP_TICKS = 1000 / FRAMES_PER_SECOND;

    DWORD next_game_tick = GetTickCount64();
    int sleep_time = 0;
    int delayCounter = 0;

    Game game;

    //Game loop
    while (game.running())
    {
        game.input();

        game.update();

        game.render(background, square, enemy, font);

        //FPS stabilisation
        next_game_tick += SKIP_TICKS;
        sleep_time = next_game_tick - GetTickCount64();
        if (sleep_time >= 0) {
            Sleep(sleep_time);
        }
        else
        {
            delayCounter++;
        }
    }

    return 0;
}