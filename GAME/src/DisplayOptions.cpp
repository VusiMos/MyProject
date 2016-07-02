#include "DisplayOptions.h"
#include <string>
#include <stdexcept>
#include <fstream>

DisplayOptions::DisplayOptions()
{
    font.loadFromFile("ARLRDBD.TTF");
    texture.loadFromFile("earth.png");
    paintBackground();
}

void DisplayOptions::paintBackground()
{
    background.setTexture(texture);
    background.setColor(Color(255, 255, 255, 200));
    background.setPosition(0,0);
}

void DisplayOptions::getOptions(RenderWindow& window, ScreenView& screenView)
{
    options(window, screenView);
}

void DisplayOptions::options(RenderWindow& window, ScreenView& screenView)
{
    Text arrow(">", font , 30);
    arrow.setStyle(Text::Regular);
    arrow.setPosition(150,100);
    arrow.setColor(Color::White);
    while (window.isOpen() && screenView == OPTIONS)
    {
        window.clear(Color::Black);
        window.draw(background);
        Event event;
        while (window.pollEvent(event))
        {
            Vector2f arrowPos = arrow.getPosition();
            if (event.type == Event::Closed)window.close();
            else if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Return)
                {
                    if(arrowPos.y == 100) changeSpeed(window,screenView);
                    if(arrowPos.y == 150) clearHighScore(window,screenView);
                }
                if (event.key.code == Keyboard::Up)
                {
                    if(arrowPos.y!=100)arrow.setPosition(arrowPos.x,arrowPos.y-50);
                }
                if (event.key.code == Keyboard::Down)
                {
                    if(arrowPos.y!=150)arrow.setPosition(arrowPos.x,arrowPos.y+50);
                }
                if (event.key.code == Keyboard::Escape) window.close();
                if (event.key.code == Keyboard::BackSpace)
                screenView = MENU;
            }
        }

        window.draw(arrow);
        screenConstants(window);
        window.display();
    }
}

void DisplayOptions::screenConstants(RenderWindow& window)
{
    display.setTextColor(Color::Yellow);
    display.displayText("Options", 50, Vector2f(200,20), window);
    display.setTextColor(Color::Red);
    display.displayText("Control Speed", 30, Vector2f(200,100), window); ///need a display. in front
    display.displayText("Clear High Score", 30, Vector2f(200,150), window); ///need a display. in front
}

void DisplayOptions::speedChanged(RenderWindow& window,ScreenView& screenView)
{
    int i = 0;
    while (window.isOpen() && screenView == OPTIONS)
    {
        window.clear(Color::Black);
        window.draw(background);
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)window.close();
            else if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::BackSpace)
                 {
                     i=1;
                    break;
                }
                if (event.key.code == Keyboard::Escape) window.close();
            }
        }
        display.displayText("Changed", 30, Vector2f(350,150), window);
        display.displayText("backspace to go back", 25, Vector2f(300,200), window);
        window.display();
        if (i==1) break;
    }
}

void DisplayOptions::changeSpeed(RenderWindow& window,ScreenView& screenView)
{
    Text arrow(">", font , 30);
    arrow.setStyle(Text::Regular);
    arrow.setPosition(150,100);
    arrow.setColor(Color::White);
   while (window.isOpen() && screenView == OPTIONS)
    {
        window.clear(Color::Black);
        window.draw(background);
        drawSpeedOptions(window);
        window.draw(arrow);
        window.display();
        Event event;
        while (window.pollEvent(event))
        {
            Vector2f arrowPos = arrow.getPosition();

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape)window.close();
                if (event.key.code == Keyboard::BackSpace)options(window,screenView);
                if (event.key.code == Keyboard::Return)
                {
                    if(arrowPos.y == 100) window.setFramerateLimit(15);
                    if(arrowPos.y == 150) window.setFramerateLimit(20);
                    if(arrowPos.y == 200) window.setFramerateLimit(25);
                    speedChanged(window,screenView);
                }
                if (event.key.code == Keyboard::Up)
                {
                    if(arrowPos.y!=100)arrow.setPosition(arrowPos.x,arrowPos.y-50);
                }
                if (event.key.code == Keyboard::Down)
                {
                    if(arrowPos.y!=200)arrow.setPosition(arrowPos.x,arrowPos.y+50);
                }
            }
        }
    }
}

void DisplayOptions::drawSpeedOptions(RenderWindow &window)
{
        display.setTextColor(Color::Yellow);
        display.displayText("SPEED OPTIONS:", 50, Vector2f(200,20), window);
        display.setTextColor(Color::Red);
        display.displayText("SLOW", 30, Vector2f(200,100), window); ///need a display. in front
        display.displayText("MEDIUM", 30, Vector2f(200,150), window); ///need a display. in front
        display.displayText("HIGH", 30, Vector2f(200,200), window); ///need a display. in front
}

void DisplayOptions::clearHighScore(RenderWindow& window,ScreenView& screenView)
{
    ofstream ofile("HighScore.txt");
    if (ofile)
    {
        ofile << "0" << endl;
    }
    while (window.isOpen() && screenView == OPTIONS)
    {
        window.clear(Color::Black);
        window.draw(background);
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)window.close();
            else if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::BackSpace) options(window,screenView);
                if (event.key.code == Keyboard::Escape) window.close();
            }
        }
        display.displayText("Cleared", 30, Vector2f(350,150), window);
        display.displayText("backspace to go back", 25, Vector2f(300,200), window);
        window.display();
    }
}

