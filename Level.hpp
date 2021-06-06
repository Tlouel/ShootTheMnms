#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <SFML/Graphics.hpp>
#include "Bullet.hpp"
#include "MnM.hpp"
#include "Spaceship.hpp"

using namespace sf;
using namespace std;

class Level 
{
    public:
        Level();
        ~Level();
        void onEvent(const Event& event);
        void update(float frametime);
        void show(RenderTarget& target);
        void start();

    private:
        Spaceship ship;
        vector<Bullet> bullets;
        vector<MnM> mnm;
};

#endif
