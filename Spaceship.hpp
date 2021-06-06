#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include <SFML/Graphics.hpp>
#include <math.h>
#include "Settings.hpp"

using namespace sf;

class Spaceship: public Drawable, public Transformable 
{
    static const float acceleration;
    static const float max_speed;
    static const float rotation_speed;

    public:
        Spaceship();
        ~Spaceship();

        void reset();
        void update(float frametime);
        void draw(RenderTarget& target, RenderStates states) const;
        void onEvent(const Event& event);

    private:
        Vector2f speed;
        ConvexShape shape;
        int h_move, v_move;
};
#endif
