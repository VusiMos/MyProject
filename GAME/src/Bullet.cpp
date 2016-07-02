#include <stdexcept>
#include <iostream>
using std::cout;
using std::end;
#include "Bullet.h"
#include "Configuration.h"

Bullet::Bullet(float x, float y, Direction dir)
{
    _position = Position();
    if(dir==UP)
    {
        _position.push_back(x+12);
        _position.push_back(y);
    }
    else
    {
        _position.push_back(x+12);
        _position.push_back(y+30);
    }
    _direction = dir;
    _lifePoints = 20;
    _speed = DEFAULTSPEED;
    _state = ALIVE;
}

void Bullet::move()
{
    if (_direction == DOWN)
    {
        moveDown();
    }
    else if (_direction == UP)
    {
        moveUp();
    }
    else if (_direction == LEFT)
    {
        moveLeft();
    }
    else if (_direction == RIGHT)
    {
        moveRight();
    }
    else
    {
        throw std::invalid_argument("TRYING TO MOVE IN INVALID DIRECTION");
    }
}
void Bullet::moveDown()
{
    if ( _position[1] < SCREENHEIGHT )
    {
        _position[1] += _speed;
    }
    else
    {
        _state = DEAD;
    }
}

void Bullet::moveUp()
{
    if ( _position[1] > 0 )
    {
        _position[1] -= _speed;
    }
    else
    {
        _state = DEAD;
    }
}

void Bullet::moveLeft()
{
    if ( _position[0] < SCREENWIDTH )
    {
        _position[0] += _speed;
    }
    else
    {
        _state = DEAD;
    }
}

void Bullet::moveRight()
{
    if ( _position[0] > 0 )
    {
        _position[0] += _speed;
    }
    else
    {
        _state = DEAD;
    }
}
