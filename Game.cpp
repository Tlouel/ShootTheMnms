#include "Game.hpp"
#include "Level.hpp"
#include "Settings.hpp"

using namespace sf;

Game::Game():
    running(true), lives(3) {
}

Game::~Game() 
{
    window.close();
}

int Game::run() 
{
    createWindow();

    Level level;
    Clock clock;

    level.start();
    while (running) 
    {
        Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == Event::Closed) 
            {
                window.close();
                return EXIT_SUCCESS;
            }
            level.onEvent(event);
        }

        window.clear();
        level.update(clock.restart().asMilliseconds());
        level.show(window);
        window.display();
    }
    return EXIT_SUCCESS;
}

void Game::createWindow() 
{
    if (window.isOpen())
        window.close();

    window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT), TITLE, Style::Close);
    window.setKeyRepeatEnabled(true);
    window.setFramerateLimit(WIN_FPS);
}
