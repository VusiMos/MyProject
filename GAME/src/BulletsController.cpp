#include "BulletsController.h"
#include <iostream>
using std::cout;
using std::endl;

void BulletsController::add(float x, float y, Direction direction)
{

   BulletPtr bullet(new Bullet(x, y, direction));
   int galaxipBullets = 0;
   int galaxianBullets = 0;
   for (auto bullet : _bullets)
     {
       if (bullet->getDirection() == UP)
         {
           galaxipBullets++;
         }
       else
         galaxianBullets++;
     }
   if (galaxipBullets < 9 && direction == UP)
     _bullets.push_back(bullet);
   else if (galaxianBullets < 5 && direction == DOWN)
     _bullets.push_back(bullet);
}

void BulletsController::update()
{
    for (auto bullet: _bullets)
       bullet->move();

    BulletList temp;
    for (BulletsListIter iter = _bullets.begin(); iter != _bullets.end(); iter++)
    {
        if ((*iter)->isAlive())
        {

            temp.push_back((*iter));
        }
    }
    _bullets.clear();
    _bullets = temp;
}

void BulletsController::setBullets(BulletList bullets)
{
    _bullets= bullets;
}
