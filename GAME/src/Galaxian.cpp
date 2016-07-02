#include "Galaxian.h"
#include <iostream>
#include <cmath>
using namespace std;


Galaxian::Galaxian(float x, float y)
{
    state_of_galaxian = ALIVE;
    xPosition = x;
    yPosition = y;
    formationXpos = x;
    formationYpos = y;
}

void Galaxian::moveLeft()
{
    if(xPosition > 0)
    {

        if (isAlive())
        {
            xPosition -= speed;
            if (yPosition < formationYpos-5)yPosition += speed;
            else if (yPosition > formationYpos+5)
            {
                yPosition = 0;
                xPosition = formationXpos;
            }
        }
            formationXpos -= speed;
    }
}

void Galaxian::moveRight()
{
    if(xPosition < 670)
    {
        if (isAlive())
        {
            xPosition += speed;
            if (yPosition < formationYpos-5) yPosition += speed;
            else if (yPosition > formationYpos+5)
            {
                yPosition = 0;
                xPosition = formationXpos;
            }
        }
            formationXpos+=speed;
    }
}

void Galaxian::dive()
{
    if (isDiving() && yPosition < 700)
    {
        if(xPosition >= 0 && xPosition <= 670)
        {
                xPosition += (2*speed*sin(yPosition/30));
                yPosition += speed;
        }
        else
        {
            if(xPosition >= 670)
            {
                xPosition += -speed;
                yPosition += speed;
            }
            else if (xPosition <= 0)
            {
                xPosition += speed;
                yPosition += speed;
            }
        }
    }
    if(yPosition >= 700) state_of_galaxian = ALIVE;
}

bool Galaxian::isAlive()
{
    return state_of_galaxian == ALIVE;
}
bool Galaxian::isDead()
{
    return state_of_galaxian==DEAD;
}
bool Galaxian::isDiving()
{
    return state_of_galaxian == DIVING;
}

void Galaxian::setState(State state)
{
    state_of_galaxian = state;
}

float Galaxian::getXpos()
{
    return xPosition;
}

float Galaxian::getYpos()
{
    return yPosition;
}
