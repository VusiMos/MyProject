#ifndef BULLET_H
#define BULLET_H
#include <vector>
#include <string>
#include <memory>
#include "Utils.h"

using std::string;
using std::vector;
using std::shared_ptr;

class Bullet
{
public:
    /** \brief Constructor
     *
     * \param  float : x coordinate of the bullet
     * \param  float : y coordinate of the bullet
     * \param  Direction : direction of the bullet
     */
  Bullet(float x, float y, Direction dir);

   /** \brief This function returns the direction of the bullet.
    *         There are two possible directions, either UP or DOWN.
    *
    * \return Direction of the Bullet
    *
    */
     Direction getDirection() { return _direction; };

  /** \brief This function moves the Bullet either UP or DOWN.
   */
  void move();

  /** \brief Checks if the bullet is alive.
   */
  bool isAlive(){ return _state == ALIVE; };

  /** \brief Checks if the bullet is Dead.
   */
  bool isDead() { return _state == DEAD; };

  /** \brief Returns current x position of the bullet.
   *
   * \return float
   *
   */
  float getXpos() { return _position[0]; };


  /** \brief Returns current y position of the bullet.
   *
   * \return float
   *
   */
  float getYpos() { return _position[1]; };

  /** \brief Sets the state of the bullet, namely DEAD or ALIVE.
   *
   * \param state State
   */
  void setState(State state) { _state = state; };


 private:
  float _lifePoints;
  Position _position;
  Direction _direction;
  State _state;
  float _speed;
  float speed();
  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();


};

typedef shared_ptr<Bullet> BulletPtr;
#endif
