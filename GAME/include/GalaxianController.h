#ifndef GALAXIANCONTROLLER_H
#define GALAXIANCONTROLLER_H
#include "Galaxian.h"
#include "Utils.h"
#include <vector>
#include <memory>

#include <iostream>
using namespace std;

class GalaxianController
{
public:
 /** \brief A constructor, which sets a flag to FALSE
     *
     */
    GalaxianController();

    /** \brief Returns bullet positions.
     *
     * \return vector of bullet positions
     *
     */
    vector< Position > getBulletPositions (){return _bulletPositions;};

    /** \brief Returns Galaxians in lower level of formation.
     *
     * \return vector of Galaxians
     *
     */
    VecOfGalaxians getVectorOfGalaxians(){return _galaxians;};

    /** \brief Returns Galaxians in second level of formation.
     *
     * \return vector of Galaxians
     *
     */
    VecOfGalaxians getVectorOfGalaxians2(){return _galaxians2;};

    /** \brief Returns flag ship escorts of type Galaxians.
     *
     * \return vector of Galaxians
     *
     */
    VecOfGalaxians getVectorOfFlagShipEscorts(){return _flagShipEscorts;};

     /** \brief Returns flag ships of type Galaxians.
     *
     * \return vector of Galaxians
     *
     */
    VecOfGalaxians getVectorOfFlagShips(){return _flagShips;};

    /** \brief Creates all the galaxians and determines how far apart they are.
     *
     */
    void createGalaxians();

    /** \brief Creates a vector of galaxians.
     *
     *  \param vector of galaxians
     */
    void setVectorOfGalaxians(VecOfGalaxians);

    /** \brief Creates a second vector of galaxians.
     *
     *  \param vector of galaxians
     */
    void setVectorOfGalaxians2(VecOfGalaxians);

    /** \brief Creates a vector of a special type of galaxian
     *          known as flagship escorts.
     *
     *  \param vector of galaxians
     */
    void setVectorOfFlagShipEscorts(VecOfGalaxians);

    /** \brief Creates a vector of a special type of galaxian
     *          known as flagships.
     *
     *  \param vector of galaxians
     */
    void setVectorOfFlagShips(VecOfGalaxians);

    /** \brief Moves galaxians and updates all galaxian vectors by making
     *          sure that dead galaxians are deleted.
     *
     */
    void update();

protected:
    /** \brief Responsible for the movement of diving galaxians.
     *
     *  \param vector of galaxians
     */
    void moveDiving(VecOfGalaxians galaxians);

    /** \brief Selects which flagships are going to dive and when
     *
     */
    void selectDivingFlagShips();

    /** \brief Randomly selects which galaxians dive bomb the galaxip
     *
     */
    void randomlySelectDivingGalaxian();

    /** \brief Responsible for the movement of diving galaxians
     *
     */
    void moveDivingObjects();

    /** \brief Responsible for the movement of galaxians which are still in formation
     *
     */
    void moveFormation();

    /** \brief Sets the state of a diving galaxian to DIVING
     *
     *  \param Pointer to a galaxian
     */
    void galaxianDiveDown(shared_ptr<Galaxian> &galaxian);

    /** \brief Finds and deletes all dead galaxians from a galaxian vector
     *
     *  \param vector of galaxians
     */
    void deleteDeadGalaxian(VecOfGalaxians &galaxians);


private:
    int num3, remainder,divingObjects, randomNum, flagShipDiveTimer = 0;
    bool flag;
    VecOfGalaxians _galaxians;
    VecOfGalaxians _galaxians2;
    VecOfGalaxians _flagShipEscorts;
    VecOfGalaxians _flagShips;
    vector< Position > _bulletPositions;
    void setFlag(VecOfGalaxians galaxians);
};

#endif // GALAXIANCONTROLLER_H
