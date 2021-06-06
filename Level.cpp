#include "Level.hpp"

using namespace std;
using namespace sf;

Level::Level() 
{
    for (int i=0; i < 15; i++) 
    {
        MnM a(0);
        mnm.push_back(a);
    }
}

Level::~Level() {
}

void Level::onEvent(const Event& event) 
{
    ship.onEvent(event);

    if (Keyboard::isKeyPressed(Keyboard::Space)) 
    {
        Bullet bullet(ship.getPosition(), ship.getRotation());
        bullets.push_back(bullet);
    }
}

void Level::update(float frametime) 
{
    ship.update(frametime);
    vector<Bullet>::iterator start_bullets = bullets.begin();

    while (start_bullets != bullets.end()) 
    {
        if (start_bullets->isAlive()) 
        {
            start_bullets->update(frametime);
            ++start_bullets;
        } 
        else
        {
            start_bullets = bullets.erase(start_bullets);
        }
    }

    vector<MnM>::iterator start_mnm = mnm.begin();

    while (start_mnm != mnm.end()) 
    {
        if (start_mnm->isAlive()) 
        {
            start_mnm->update(frametime);
            ++start_mnm;
        } 
        else
        {
            start_mnm = mnm.erase(start_mnm);
        }
    }

    vector<MnM> new_mnm;
    start_mnm = mnm.begin();

    while (start_mnm != mnm.end()) 
    {
        start_bullets = bullets.begin();

        while (start_bullets != bullets.end()) 
        {
            if (!start_bullets->isAlive()) 
            {
                ++start_bullets;
                continue;
            }

            if (start_mnm->checkPoint(start_bullets->getPosition()))
            {
                start_bullets->kill();
                start_mnm->breakDown();

                if (start_mnm->isAlive()) 
                {
                    Vector2f position = start_mnm->getPosition();
                    float angle = rand() % 360;
                    MnM m(position, angle, start_mnm->getLevel());
                    new_mnm.push_back(m);
                }
                break;
            }
            ++start_bullets;
        }
        ++start_mnm;
    }
    mnm.insert(mnm.end(), new_mnm.begin(), new_mnm.end());
}

void Level::show(RenderTarget& target) 
{
    target.draw(ship);

    for (vector<Bullet>::iterator i = bullets.begin(); i != bullets.end(); ++i)
    {
        target.draw(*i);
    }

    for (vector<MnM>::iterator i = mnm.begin(); i != mnm.end(); ++i)
    {
        target.draw(*i);
    }
}

void Level::start() {
}
