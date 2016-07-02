#ifndef GALAXIP_H
#define GALAXIP_H
#include "Utils.h"

class Galaxip
{
public:

    /** \brief Default Constructor
     *
     * Initialises the private members of the class.
     */
     Galaxip();

    /** \brief Returns true galaxip if ALIVE.
     *
     * \return bool
     *
     */
    bool isAlive();

    /** \brief Returns a float which represents the x coordinate of the galaxip.
     *
     * \return float
     *
     */
    float getXpos();

    /** \brief Returns a float which represents the y coordinate of the galaxip.
     *
     * \return float
     *
     */
    float getYpos();

    /** \brief Sets the state of the galaxip, namely dead or alive.
     *
     * \param state State
     * \return void
     *
     */
    void setState(State state);

    /** \brief Moves the galaxip to the left.
     *
     */
    void moveLeft();

    /** \brief Moves the galaxip to the right.
     *
     */
    void moveRight();

protected:

private:
    int speed;
    float xPosition;
    float yPosition;
    State state_of_galaxip;
};

#endif // GALAXIP_H
