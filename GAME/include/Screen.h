/** \mainpage
 *
 *  Welcome to the official documentation of Princess Galaxian.\n
 *
 *  Here you will find a comprehensive insight of all the classes
 *  and functions of Princess Galaxian.
 */

#ifndef SCREEN_H
#define SCREEN_H
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "DisplayMenu.h"
#include "DisplayGame.h"
#include "DisplayHelp.h"
#include "DisplayOptions.h"

using namespace sf;

class Screen
{
    public:
        /** \brief Default constructor
         *
         * Creates a Screen object and initialising the window.
         * It limits the framerate to 10 and sets the screen view
         * to menu.
         */
        Screen();
        /** \brief Selects the View to show based on the user choice
         * during navigation of the menu
         *
         */
        void display();
        /** \brief Displays the menu
         *
         */
        void accessMenu();
        /** \brief Fetches necessary classes and/or functions to display the game.
         *
         */
        void accessGame();
        /** \brief Displays the help menu
         *
         */
        void accessHelp();
        /** \brief Displays the options menu which allows you to control the speed
         * and reset the high score.
         *
         */
        void accessOptions();
       private:
        RenderWindow window;
        ScreenView _screenView;
        DisplayMenu menu;
        DisplayGame game;
        DisplayHelp help;
        DisplayOptions options;
};

#endif // SCREEN_H
