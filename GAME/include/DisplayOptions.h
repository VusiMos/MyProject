#ifndef DISPLAYOPTIONS_H
#define DISPLAYOPTIONS_H
#include "Utils.h"
#include "DrawText.h"

class DisplayOptions
{
    public:
        /** \brief Default Constructor
         *
         * It initialises the private data members of the class.
         */
        DisplayOptions();

        /** \brief Responsible for the display of the options menu.
         *
         * \param RenderWindow&
         * \param ScreenView&
         */
        void getOptions(RenderWindow&, ScreenView&);

    protected:
        void clearHighScore(RenderWindow&,ScreenView&);
        void changeSpeed(RenderWindow&,ScreenView&);
        void drawSpeedOptions(RenderWindow&);
        void options(RenderWindow&,ScreenView&);
        void paintBackground();
        void screenConstants(RenderWindow&);
        void speedChanged(RenderWindow&,ScreenView&);

    private:
        DrawText display;
        Font font;
        Sprite  background;
        Texture texture;
};

#endif // DISPLAYOPTIONS_H
