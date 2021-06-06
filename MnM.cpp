#include "MnM.hpp"

using namespace sf;

const float MnM::speed[5] = {0.03f, 0.05f, 0.07f, 0.1f, 0.08f};
const float MnM::radius[5] = {40.0f, 20.0f, 10.0f, 70.0f, 55.0f};

MnM::MnM(int level):
    is_alive(true),
    level(level) 
{
    int angle = rand() % 360;
    direction = Vector2f(cos(angle * DEGTORAD), sin(angle * DEGTORAD));

    int x = rand() % WIN_WIDTH;
    int y = rand() % WIN_HEIGHT;

    Vector2f position(x, y);
    setPosition(position);
    shape.setPointCount(8);
    shape.setRadius(radius[level]);
    shape.setFillColor(Color::Black);
    shape.setOutlineColor(Color(rand() % 255, rand() % 255, rand() % 255));
    shape.setOutlineThickness(3);
    shape.setOrigin(radius[level], radius[level]);
}

MnM::MnM(Vector2f position, float angle, int level):
    is_alive(true),
    level(level) 
{
    direction = sf::Vector2f(cos(angle * DEGTORAD), sin(angle * DEGTORAD));

    setPosition(position);
    shape.setPointCount(8);
    shape.setRadius(radius[level]);
    shape.setFillColor(Color::Black);
    shape.setOutlineColor(Color(rand() % 255, rand() % 255, rand() % 255));
    shape.setOutlineThickness(1);
    shape.setOrigin(radius[level], radius[level]);
}

MnM::~MnM() {
}

bool MnM::isAlive() 
{
    return is_alive;
}

void MnM::update(float frametime) 
{
    if (!is_alive) return;

    Vector2f distance = direction * speed[level] * frametime;
    move(distance);

    Vector2f position = getPosition();

    if (position.x < -radius[level])
    {
        position.x = WIN_WIDTH;
    }
    else if (position.x > WIN_WIDTH)
    {
        position.x = 0.0f;
    }

    if (position.y < -radius[level])
    {
        position.y = WIN_HEIGHT;
    }
    else if (position.y > WIN_HEIGHT)
    {
        position.y = 0.0f;
    }

    setPosition(position);
}

void MnM::draw(RenderTarget& target, RenderStates states) const 
{
    states.transform *= getTransform();
    target.draw(shape, states);
}

int MnM::getLevel() 
{
    return level;
}

void MnM::breakDown() 
{
    level++;

    if (level > 2) 
    {
        is_alive = false;
        return;
    }

    shape.setRadius(radius[level]);
    shape.setOrigin(radius[level], radius[level]);
    float angle = rand() % 360;
    direction = Vector2f(cos(angle * DEGTORAD), sin(angle * DEGTORAD));
}

bool MnM::checkPoint(Vector2f point) 
{
    float ax = getPosition().x;
    float ay = getPosition().y;

    float px = point.x;
    float py = point.y;

    float sqrDistance = ((ax - px) * (ax - px)) + ((ay - py) * (ay - py));
    float sqrRadius = radius[level] * radius[level];

    return (sqrDistance <= sqrRadius);
}
