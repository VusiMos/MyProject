#ifndef DISPLAYHELP_H
#define DISPLAYHELP_H
#include "Utils.h"
#include "DrawText.h"

class DisplayHelp
{
    public:
        /** \brief Default Constuctor
         *
         * Sets the font and background for the help view.
         */
        DisplayHelp();
        /** \brief Draws the help menu on the window and allows the navigation of the
         * back to the menu.
         *
         * \param window RenderWindow&
         * \param screenView ScreenView&
         */
        void getHelp(RenderWindow& window, ScreenView& screenView);

    private:
        void help(RenderWindow& window, ScreenView& screenView);
        void paintBackground();
        void screenConstants(RenderWindow& window);
        DrawText display;
        Sprite  background;
        Texture texture;
};

#endif // DISPLAYHELP_H
