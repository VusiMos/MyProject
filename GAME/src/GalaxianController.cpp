#include "GalaxianController.h"
#include <cstdlib>
#include <time.h>

GalaxianController::GalaxianController()
{
    flag = false;
}

void GalaxianController::createGalaxians()
{
    for (int i =20; i<500; i+=50)
    {
        for (int j =20; j<230; j+=50)
        {
            if ((i > 210) && (i < 370) && (j == 20))
            {
                shared_ptr<Galaxian> flagShip(new Galaxian(i,j));
                _flagShips.push_back(flagShip);
            }
            if ((i > 160) && (i < 420) && (j == 70))
            {
                shared_ptr<Galaxian> flagShipEscort(new Galaxian(i,j));
                _flagShipEscorts.push_back(flagShipEscort);
            }
            if ((i > 110) && (i < 470) && (j == 120))
            {
                shared_ptr<Galaxian> galaxian2(new Galaxian(i,j));
                _galaxians2.push_back(galaxian2);
            }
            if ((i > 20) && (i < 500)&& (j >= 170))
            {
                shared_ptr<Galaxian> galaxian(new Galaxian(i,j));
                _galaxians.push_back(galaxian);
            }
        }
    }
}

void GalaxianController::galaxianDiveDown(shared_ptr<Galaxian> &galaxian)
{
    galaxian->setState(DIVING);
}

void GalaxianController::moveFormation()
{
    unsigned int number_of_dead_galaxians = 0;
    for (auto iter=begin(_galaxians); iter!=end(_galaxians); ++iter)
    {
        if((*iter)->isDead())number_of_dead_galaxians++;
        if(flag == false) (*iter)->moveLeft();
        else(*iter)->moveRight();
    }
    for (auto iter=begin(_galaxians2); iter!=end(_galaxians2); ++iter)
    {
        if((*iter)->isDead())number_of_dead_galaxians++;
        if(flag == false) (*iter)->moveLeft();
        else(*iter)->moveRight();
    }
    for (auto iter=begin(_flagShipEscorts); iter!=end(_flagShipEscorts); ++iter)
    {
        if((*iter)->isDead())number_of_dead_galaxians++;
        if(flag == false) (*iter)->moveLeft();
        else(*iter)->moveRight();
    }
    for (auto iter=begin(_flagShips); iter!=end(_flagShips); ++iter)
    {
        if((*iter)->isDead())number_of_dead_galaxians++;
        if(flag == false) (*iter)->moveLeft();
        else(*iter)->moveRight();
    }
}

void GalaxianController::randomlySelectDivingGalaxian()
{
    for (auto iter=begin(_galaxians); iter!=end(_galaxians); ++iter)
    {
        if((*iter)->isAlive())
        {
            num3 = (rand() % (2000)) + 1;
            if (num3 == 53) galaxianDiveDown((*iter));
        }
    }
}

void GalaxianController::selectDivingFlagShips()
{
    auto iter = end(_flagShips) - 1;
    if (iter != begin(_flagShips) - 1)
    {
        galaxianDiveDown((*iter));
        if (_flagShipEscorts.size() != 0)iter =  end(_flagShipEscorts) - 1;
        galaxianDiveDown((*iter));
        if (_flagShipEscorts.size()>1)iter =  end(_flagShipEscorts) - 2;
        galaxianDiveDown((*iter));
    }
}

void GalaxianController::moveDiving(VecOfGalaxians galaxians)
{
    divingObjects = 0;
    for (auto iter=begin(galaxians); iter!=end(galaxians); ++iter)
    {
        if((*iter)->isDiving())
        {
            randomNum= (rand() % (100)) + 1;
            remainder =randomNum%10;
            Position pos;
            if(remainder == 7 )
            {
                pos.push_back((*iter)->getXpos());
                pos.push_back((*iter)->getYpos());
                _bulletPositions.push_back(pos);
            }
            (*iter)->dive();
            divingObjects++;
        }
    }
}

void GalaxianController::moveDivingObjects()
{
    _bulletPositions.clear();
    moveDiving(_galaxians);
    moveDiving(_flagShipEscorts);
    moveDiving(_flagShipEscorts);
    moveDiving(_flagShips);
    moveDiving(_flagShips);
    moveDiving(_flagShips);
    setFlag(_galaxians);
    setFlag(_galaxians2);
    setFlag(_flagShips);
    setFlag(_flagShipEscorts);
}

void GalaxianController::setFlag(VecOfGalaxians galaxians)
{
    for (auto iter=begin(galaxians); iter!=end(galaxians); ++iter)
    {
        if(!(*iter)->isDead() && (*iter)->getXpos() <= 0 )
        {
            flag = true;
        }
        if(!(*iter)->isDead() && (*iter)->getXpos() >= 670 )
        {
            flag = false;
        }
    }
}

void GalaxianController::update()
{
    moveDivingObjects();
    moveFormation();
    if (divingObjects < 4)randomlySelectDivingGalaxian();
    if (flagShipDiveTimer == 200)
    {
        flagShipDiveTimer = 0;
        selectDivingFlagShips();
    }
    deleteDeadGalaxian(_galaxians);
    deleteDeadGalaxian(_galaxians2);
    deleteDeadGalaxian(_flagShipEscorts);
    deleteDeadGalaxian(_flagShips);
    flagShipDiveTimer++;
}

void GalaxianController::deleteDeadGalaxian(VecOfGalaxians &galaxians)
{
    VecOfGalaxians temp;
    for (auto galaxian : galaxians)
    {
        if (!galaxian->isDead())
        {
            temp.push_back(galaxian);
        }
    }
    galaxians.clear();
    galaxians = temp;
}

void GalaxianController::setVectorOfGalaxians(VecOfGalaxians galaxians)
{
    _galaxians = galaxians;
}

void  GalaxianController::setVectorOfGalaxians2(VecOfGalaxians galaxians2)
{
    _galaxians2 = galaxians2;
}
void  GalaxianController::setVectorOfFlagShipEscorts(VecOfGalaxians flagShipEscorts)
{
    _flagShipEscorts = flagShipEscorts;
}
void  GalaxianController::setVectorOfFlagShips(VecOfGalaxians flagShips)
{
    _flagShips = flagShips;
}
