#include "DisplayMenu.h"

DisplayMenu::DisplayMenu()
{
    font.loadFromFile("ARLRDBD.TTF");
    texture.loadFromFile("earth.png");
    paintBackground();
}
void DisplayMenu::paintBackground()
{
    background.setTexture(texture);
    background.setColor(Color(255, 255, 255, 200));
    background.setPosition(0,0);
}
void DisplayMenu::drawMenuOptions(RenderWindow &window)
{
        display.setTextColor(Color::Yellow);
        display.displayText("MENU", 50, Vector2f(200,20), window);
        display.setTextColor(Color::Red);
        display.displayText("START GAME", 30, Vector2f(200,100), window); ///need a display. in front
        display.displayText("OPTIONS", 30, Vector2f(200,150), window); ///need a display. in front
        display.displayText("HELP", 30, Vector2f(200,200), window); ///need a display. in front
}
void DisplayMenu::getMenu(RenderWindow& window, ScreenView &screenView)
{
    Text arrow(">", font , 30);
    arrow.setStyle(Text::Regular);
    arrow.setPosition(150,100);
    arrow.setColor(Color::White);
    while (window.isOpen() && screenView == MENU)
    {
        window.clear(Color::Black);
        window.draw(background);
        color = Color::Red;
        drawMenuOptions(window);
        color = Color::White;
        window.draw(arrow);
        window.display();
        Event gamemenu;
        while (window.pollEvent(gamemenu))
        {
            Vector2f arrowPos = arrow.getPosition();

            if (gamemenu.type == Event::KeyPressed)
            {
                if (gamemenu.key.code == Keyboard::Escape)window.close();
                if (gamemenu.key.code == Keyboard::Return)
                {
                    if(arrowPos.y == 100) screenView = GAME;
                    if(arrowPos.y == 150) screenView = OPTIONS;
                    if(arrowPos.y == 200) screenView = HELP;
                }
                if (gamemenu.key.code == Keyboard::Up)
                {
                    if(arrowPos.y!=100)arrow.setPosition(arrowPos.x,arrowPos.y-50);
                }
                if (gamemenu.key.code == Keyboard::Down)
                {
                    if(arrowPos.y!=200)arrow.setPosition(arrowPos.x,arrowPos.y+50);
                }
            }
        }
    }
}
