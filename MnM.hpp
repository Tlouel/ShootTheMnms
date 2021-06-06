#ifndef MNM_HPP
#define MNM_HPP

#include <SFML/Graphics.hpp>
#include <math.h>
#include "Settings.hpp"

using namespace sf;

class MnM: public Drawable, public Transformable 
{
    static const float speed[5];
    static const float radius[5];

    public:
        MnM(int level);
        MnM(Vector2f position, float angle, int level);
        ~MnM();

        bool isAlive();
        int getLevel();
        bool checkPoint(Vector2f point);
        void breakDown();
        void update(float frametime);
        void draw(RenderTarget& target, RenderStates states) const;

    private:
        int level;
        bool is_alive;
        Vector2f direction;
        CircleShape shape;
};
#endif
