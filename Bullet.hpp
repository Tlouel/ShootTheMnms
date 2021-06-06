#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>
#include <math.h>
#include "Settings.hpp"

using namespace sf;

class Bullet: public Drawable, public Transformable 
{
    static const float lifetime;
    static const float speed;

    public:
        Bullet(Vector2f position, float angle);
        ~Bullet();

        bool isAlive();
        void kill();
        void update(float frametime);
        void draw(RenderTarget& target, RenderStates states) const;

    private:
        bool is_alive;
        float remaining_life;
        sf::Vector2f direction;
};
#endif
