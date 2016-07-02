#ifndef BULLE0ULLETCONTROLLER_H
#include <vector>
#include "Bullet.h"
using std::vector;
typedef vector<BulletPtr> BulletList;
typedef vector<BulletPtr>::iterator BulletsListIter;

class BulletsController
{
 public:
  /** \brief A function which adds a new Bullet to the list of
   *  bullets as it is created. It takes in the x and y position
   *  co-ordinate of the bullet as well as the direction.
   *
   * \param float
   * \param float
   * \param Direction
   */
  void add(float, float, Direction);

  /** \brief  It returns the list of bullets.
   *
   * \return BulletList
   *
   */
  BulletList getBullets() {return _bullets; };


  /** \brief Moves the bullets and removes 'dead' bullets
   *
   */
  void update();


  /** \brief Creates a list of bullets
   *
   * \param BulletList
   */
  void setBullets(BulletList );

 private:
  BulletList _bullets;

};
#endif
