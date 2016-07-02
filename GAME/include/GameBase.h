#ifndef GAMEBASE_H
#define GAMEBASE_H
#include "CollisionDetector.h"


using namespace std;

/** \brief An enum type.
 *
 * GameState is an enum type which has three possible values
 * Paused, Online and GameOver.
 * These are used to determine what state the game is in.
 */
typedef enum
{
    Paused,
    Online,
    GameOver
} GameState;

class GameBase
{
public:
    /** \brief Default Constructor
     *
     * It starts the game by setting the state to online
     *         and creates galaxians.
     */
    GameBase();

    /** \brief Returns the state of the game, namely; Paused, Online and GameOver.
     *
     * \return GameState
     *
     */
    GameState getState(){return state;};

    /**  Allows
     */
    /** \brief Returns the galaxip.
     *
     * \return Galaxip
     *
     */
    Galaxip getGalaxip(){return galaxip;};

    /** \brief Allows access to the score
     *
     * \return int
     *
     */
    int getScore() {return score;};

    /** \brief Returns true if win is true.
     *
     * \return bool
     *
     */
    bool youWin() {return win==true;};

    /** \brief Allows access to a vector of galaxians.
     *
     * \return VecOfGalaxians
     *
     */
    VecOfGalaxians getVectorOfGalaxians() {return galaxians;};


    /** \brief Allows access to a second vector of galaxians.
     *
     * \return VecOfGalaxians
     *
     */
    VecOfGalaxians getVectorOfGalaxians2(){return galaxians2;};

    /** \brief Returns a vector of galaxians, of type escorts.
     *
     * \return VecOfGalaxians
     *
     */
    VecOfGalaxians getVectorOfFlagShipEscorts(){return flagShipEscorts;};

    /** \brief Returns a vector of galaxians, of type flagships
     *
     * \return VecOfGalaxians
     *
     */
    VecOfGalaxians getVectorOfFlagShips(){return flagShips;};

    /** \brief Returns a list of bullets
     *
     * \return BulletList
     *
     */
    BulletList getVectorOfBullets() {return bullets;};

    /** \brief Allows creation of all Galaxian type objects
     *
     */
    void createGalaxians();

    /** \brief  Ensures that diving galaxians return to their correct
     *   position in formation.
     */
    void returnDivingToFormation();

    /** \brief Ensures that all game objects are in a valid state and
     *   are up to date.
     */
    void gameLogic();

    /** \brief responsible for galaxians shooting bullets.
     *
     * Takes in a vector containing the positions of galaxians so that the bullets are shot
     *        from the right position.
     *
     * \param vector <Position>
     *
     */
    void shootGalaxianBullet(vector <Position>);

    /** \brief Responsible for the galaxip shooting bullets.
     *
     */
    void shootGalaxipBullet();

    /** \brief Sets the state of the game.
     *
     * \param GameState
     */
    void setState(GameState );

    /** \brief Responsible for the galaxip moving left.
     *
     */
    void galaxipMoveleft();

    /** \brief Responsible for the galaxip moving right.
     */
    void galaxipMoveRight();

protected:
    /**  \brief Allows access to all types of galaxians.
     */
    void getGalaxianVectors();

    /**  \brief Makes sure that the vector of galaxians is up to date and in a valid state.
     */
    void setGalaxianVectors();

    /**  \brief Returns true if all Galaxians are dead.
     */
    bool allGalaxiansDead();

private:
    bool win;
    int score;
    Galaxip galaxip;
    BulletList bullets;
    GameState state;
    VecOfGalaxians galaxians;
    VecOfGalaxians galaxians2;
    VecOfGalaxians flagShipEscorts;
    VecOfGalaxians flagShips;
    BulletsController bulletsController;
    GalaxianController galaxianController;
};

#endif // GAMEBASE_H
