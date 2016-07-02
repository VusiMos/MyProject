#include "Galaxip.h"

Galaxip::Galaxip()
{
    xPosition = 300;
    yPosition = 600;
    speed = 30;
    state_of_galaxip = ALIVE;

}

void Galaxip::moveLeft()
{
    if(xPosition > 0) xPosition -= speed;
}

void Galaxip::moveRight()
{
    if(xPosition < 660)xPosition += speed;
}

bool Galaxip::isAlive()
{
    return state_of_galaxip == ALIVE;
}

void Galaxip::setState(State state)
{
    state_of_galaxip = state;
}

float Galaxip::getXpos()
{
    return xPosition;
}

float Galaxip::getYpos()
{
    return yPosition;
}

