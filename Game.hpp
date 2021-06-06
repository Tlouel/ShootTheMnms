#ifndef GAME_HPP
#define GAME_HPP

using namespace sf;

#include <SFML/Graphics.hpp>

class Game
{
    public:
        Game();
        ~Game();
        int run();
        void quit();

    private:
        void createWindow();
        RenderWindow window;
        bool running;
        int lives;
};

#endif
