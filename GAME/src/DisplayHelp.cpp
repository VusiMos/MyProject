#include "DisplayHelp.h"
#include <string>
#include <stdexcept>
#include <fstream>

using namespace std;
DisplayHelp::DisplayHelp()
{
    texture.loadFromFile("earth.png");
    paintBackground();
}
void DisplayHelp::paintBackground()
{
    background.setTexture(texture);
    background.setColor(Color(255, 255, 255, 200));
    background.setPosition(0,0);
}
void DisplayHelp::getHelp(RenderWindow& window, ScreenView& screenView)
{
    help(window, screenView);
}
void DisplayHelp::help(RenderWindow& window, ScreenView& screenView)
{
    while (window.isOpen() && screenView == HELP)
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();
            else if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape) window.close();
                if (event.key.code == Keyboard::BackSpace) screenView = MENU;
            }
        }
        window.clear();
        window.draw(background);
        screenConstants(window);
        window.display();
    }
}
void DisplayHelp::screenConstants(RenderWindow& window)
{
    string line;
    int yPos = 0;

    display.setTextColor(Color::White);
    display.setFont("font.ttf");

    ifstream filereader("help.txt");
    if (!filereader) throw logic_error("help.txt could not be opened");
    while (getline(filereader, line))
    {
        yPos += +30;
        display.displayText(line, 30, Vector2f(20,yPos), window);
    }
    display.setFont("transformers_movie.ttf");
}
