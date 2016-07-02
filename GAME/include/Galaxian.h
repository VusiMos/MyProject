#ifndef GALAXIAN_H
#define GALAXIAN_H
#include <vector>
#include <memory>
#include "Utils.h"

using std::vector;
using namespace std;

class Galaxian
{
public:
     /** \brief Constructor
     *
     * It sets the x and y coordinates of a galaxian.
     *
     * \param x float
     * \param y float
     *
     */
    Galaxian(float x, float y);

    /** \brief Returns the x position of a galaxian.
     *
     * \return float
     *
     */
    float getXpos();

    /** \brief Returns the y position of a galaxian.
     *
     * \return float
     *
     */
    float getYpos();

    /** \brief Returns true if the galaxian is ALIVE.
     *
     * \return bool
     *
     */
    bool isAlive();

    /** \brief Returns true if the galaxian is DEAD.
     *
     * \return bool
     *
     */
    bool isDead();

    /** \brief Returns true if the galaxian is DIVING.
     *
     * \return bool
     *
     */
    bool isDiving();

    /** \brief Moves a galaxian a galaxian to the left.
     *
     */
    void moveLeft();

    /** \brief Moves a galaxian a galaxian to the right.
     *
     */
    void moveRight();

    /** \brief Controls how the galaxian dives.
     *
     */
    void dive();

    /** \brief Sets the state of a galaxian to DEAD or ALIVE.
     *
     */
    void setState(State state);



protected:

private:
    float formationXpos;
    float formationYpos;
    float xPosition;
    float yPosition;
    State state_of_galaxian;
    double speed = 8;

};
typedef vector< shared_ptr<Galaxian> > VecOfGalaxians;
#endif // GALAXIAN_H
