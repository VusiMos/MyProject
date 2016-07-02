#include "Screen.h"

Screen::Screen()
{
    window.create(VideoMode(900,700),"GALAXIAN 3.0" );
    window.setFramerateLimit(10);
    _screenView = MENU;
}

void Screen::accessMenu()
{
    menu.getMenu(window,_screenView);
}

void Screen::accessGame()
{
    DisplayGame newGame;
    //game = newGame;
    newGame.getGame(window,_screenView);
}

void Screen::accessHelp()
{
    help.getHelp(window,_screenView);
}

void Screen::accessOptions()
{
    options.getOptions(window,_screenView);
}

void Screen::display()
{
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape)window.close();
            }
        }
        switch(_screenView)
        {
        case MENU:
            accessMenu();
            break;
        case OPTIONS:
            accessOptions();
            break;
        case HELP:
            accessHelp();
            break;
        case GAME:
            accessGame();
            break;
        default:
            ;
        }
    }
}
