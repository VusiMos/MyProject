#ifndef DRAWOBJECTS_H
#define DRAWOBJECTS_H
#include "DrawText.h"


class DrawObjects
{
public:
    /** \brief Default Constructor
     *
     */
    DrawObjects();

    /** \brief Draws Galaxian objects, Galaxip object and the Bullet objects on to the window.
     *
     * \param RenderWindow&
     * \param VecOfGalaxians
     * \param VecOfGalaxians
     * \param VecOfGalaxians
     * \param VecOfGalaxians
     * \param BulletList
     * \param Galaxip
     */
    void drawObjects(RenderWindow&,VecOfGalaxians,VecOfGalaxians,VecOfGalaxians,VecOfGalaxians,BulletList, Galaxip);

private:
    Texture texture;
    Color color;
    void drawBullets(RenderWindow& window, BulletList bullets);
    void drawGalaxians(VecOfGalaxians galaxians, RenderWindow& window);
    void drawShip(Texture texture, float x, float y, RenderWindow&);
    void drawBullet(float x, float y, RenderWindow&);
    bool win = false;
};

#endif // DRAWOBJECTS_H
