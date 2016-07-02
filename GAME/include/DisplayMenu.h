#ifndef DISPLAYMENU_H
#define DISPLAYMENU_H
#include "Utils.h"
#include "DrawText.h"

class DisplayMenu
{
public:
    /** \brief Default Constructor
     *
     * Sets the font and the background of the menu view.
     */
    DisplayMenu();
    /** \brief Draws the menu on to the window allowing the navigation
     * of various options.
     *
     * \param RenderWindow&
     * \param ScreenView&
     */
    void getMenu(RenderWindow&, ScreenView&);

private:
    void drawMenuOptions(RenderWindow &window);
    void paintBackground();
    DrawText display;
    Font font;
    Color color;
    Sprite  background;
    Texture texture;
};

#endif // DISPLAYMENU_H
