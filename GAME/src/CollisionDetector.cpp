#include "CollisionDetector.h"
#include <iostream>
using namespace std;

CollisionDetector::CollisionDetector()
{
    score = 0;
    _gameOver = false;
}

bool CollisionDetector::hasCollided (shared_ptr<Galaxian> alienship, BulletPtr bullet)
{
    if((bullet->getYpos()-BULLETRADIUS) >= alienship->getYpos() && (bullet->getYpos()-BULLETRADIUS) <= (alienship->getYpos() + 40))
    {
        if(((bullet->getXpos()-BULLETRADIUS) >= alienship->getXpos() && (bullet->getXpos()-BULLETRADIUS) <= alienship->getXpos()+30) ||((bullet->getXpos()+BULLETRADIUS) >= alienship->getXpos() && (bullet->getXpos()+BULLETRADIUS) <= alienship->getXpos()+30))
            return true;
    }
    return false;
}

bool CollisionDetector::hasCollided (shared_ptr<Galaxian> alienship, Galaxip galaxip)
{
    if((alienship->getYpos()+40 >= galaxip.getYpos() && alienship->getYpos()+40 <= galaxip.getYpos()+40)||(alienship->getYpos() >= galaxip.getYpos() && alienship->getYpos() <= galaxip.getYpos()+40) )
    {
        if((alienship->getXpos() >= galaxip.getXpos() && alienship->getXpos() <= galaxip.getXpos()+30) || (alienship->getXpos()+30 >= galaxip.getXpos() && alienship->getXpos()+30 <= galaxip.getXpos()+30))return true;
    }
    return false;
}

bool CollisionDetector::hasCollided(BulletPtr alienship, BulletPtr galaxip)
{
    if((alienship->getYpos()+3 >= galaxip->getYpos()-3 && alienship->getYpos()+3 <= galaxip->getYpos()+3))
    {
        if((alienship->getXpos()-3 >= galaxip->getXpos()-3 && alienship->getXpos()-3 <= galaxip->getXpos()+3) || (alienship->getXpos()+3 >= galaxip->getXpos()-3 && alienship->getXpos()+3 <= galaxip->getXpos()+3))return true;
    }
    return false;
}

bool CollisionDetector::hasCollided (Galaxip galaxip, BulletPtr bullet)
{
    if( bullet->getYpos()+BULLETRADIUS >= galaxip.getYpos() && bullet->getYpos()+BULLETRADIUS <= galaxip.getYpos()+40)
    {
        if((bullet->getXpos()-BULLETRADIUS >= galaxip.getXpos() && bullet->getXpos()-BULLETRADIUS <= galaxip.getXpos()+30 )|| (bullet->getXpos()+BULLETRADIUS >= galaxip.getXpos() && bullet->getXpos()+BULLETRADIUS <= galaxip.getXpos()+30)) return true;
    }
    return false;
}

void CollisionDetector::checkGalaxianAndBullet(VecOfGalaxians  &galaxians,BulletList &bullets, int damagePoints)
{
    for (auto galaxian : galaxians)
    {
        for (auto bullet : bullets)
        {
            if (!galaxian->isDead() && !bullet->isDead() && bullet->getDirection() == UP)
            {
                if (hasCollided (galaxian,bullet))
                {
                    if (galaxian->isDiving()) score += 50;
                    score += damagePoints;
                    galaxian->setState(DEAD);
                    bullet->setState(DEAD);
                }
            }
        }
    }
}

void CollisionDetector::checkGalaxianAndGalaxip(VecOfGalaxians  &galaxians, Galaxip & galaxip)
{
    for (auto galaxian : galaxians)
    {
        if (galaxian->isDiving())
        {
            if (hasCollided (galaxian,galaxip))
            {
                galaxian->setState(DEAD);
                galaxip.setState(DEAD);
                _gameOver = true;
            }
        }
    }
}

void CollisionDetector::checkGalaxipAndBullet(Galaxip  &galaxip, BulletList &bullets)
{
    for (auto bullet : bullets)
    {
        if(!bullet->isDead() && bullet->getDirection() == DOWN)
        {
            if (hasCollided(galaxip,bullet))
            {
                bullet->setState(DEAD);
                galaxip.setState(DEAD);
                _gameOver = true;
            }
        }
    }
}

void CollisionDetector::checkGalaxipBulletAndGalaxianBullet(BulletList & bullets,int damagePoints)
{
    for (auto iter=begin(bullets); iter!=end(bullets); ++iter)
    {
        if(!(*iter)->isDead()&& (*iter)->getDirection()== DOWN)
        {
            for (auto bullet2 : bullets )
            {
                if(!bullet2->isDead() && bullet2->getDirection()== UP)
                {
                    if (hasCollided(*iter,bullet2))
                    {
                        (*iter)->setState(DEAD);
                        bullet2->setState(DEAD);
                        score += damagePoints;
                    }
                }
            }
        }
    }
}

void CollisionDetector::checkCollisions(VecOfGalaxians &galaxians,VecOfGalaxians &galaxians2,VecOfGalaxians &flagShipEscorts,VecOfGalaxians &flagShips, BulletList &bullets, Galaxip &galaxip)
{
    checkGalaxianAndBullet(galaxians,bullets,20);
    checkGalaxianAndBullet(galaxians2,bullets,50);
    checkGalaxianAndBullet(flagShipEscorts,bullets,100);
    checkGalaxianAndBullet(flagShips,bullets,150);
    checkGalaxianAndGalaxip(galaxians,galaxip);
    checkGalaxianAndGalaxip(galaxians2, galaxip);
    checkGalaxianAndGalaxip(flagShipEscorts,galaxip);
    checkGalaxianAndGalaxip(flagShipEscorts,galaxip);
    checkGalaxipAndBullet(galaxip,bullets);
    checkGalaxipBulletAndGalaxianBullet(bullets,60);
    int divingEscorts = 0;
    if (flagShips.size() != 0)
    {
        auto iter = end(flagShips) - 1;
        if ((*iter)->isDead())
        {
            if (flagShipEscorts.size() != 0)iter =  end(flagShipEscorts) - 1;
            {
                if ((*iter)->isDead()) divingEscorts++;
            }
            if (flagShipEscorts.size()>1)iter =  end(flagShipEscorts) - 2;
            {
                if ((*iter)->isDead()) divingEscorts++;
            }
        }
        if(divingEscorts == 2) score += 100;
        if(divingEscorts == 1) score += 50;
    }
}
