#include "DisplayGame.h"
#include <iomanip>
#include <locale>
#include <string>
#include <sstream>
#include <stdexcept>
#include <fstream>

using namespace std;

DisplayGame::DisplayGame()
{
    win = false;
    score = 0;
    numOfLives = 3;
    texture.loadFromFile("space.jpg");
    paintBackground();
}

void DisplayGame::getGame(RenderWindow& window, ScreenView &screenView)
{
    startGame(window , screenView);
}

void DisplayGame::screenConstants(RenderWindow& window)
{
    RectangleShape rectangle(Vector2f(5,700));
    rectangle.setFillColor(Color::Blue);
    rectangle.setPosition(700,0);
    window.draw(rectangle);
    display.displayText("HIGHEST SCORE:", 20, Vector2f(710,30),window);
    display.displayText("SCORE:", 20, Vector2f(710,200),window);
    score = gamelogic.getScore();
    display.displayText(convertToString(score), 50, Vector2f(750,300),window);
    display.displayText("LIVES:", 20, Vector2f(710,400),window);
    display.displayText(convertToString(numOfLives), 50, Vector2f(750,450),window);
    display.displayText("SPECIAL WEAPON:", 20, Vector2f(710,550),window);
    display.displayText("unavailable", 15, Vector2f(760,630),window);

}

void DisplayGame::getGameObjects()
{
    galaxip = gamelogic.getGalaxip();
    galaxians = gamelogic.getVectorOfGalaxians();
    galaxians2 = gamelogic.getVectorOfGalaxians2();
    flagShipEscorts = gamelogic.getVectorOfFlagShipEscorts();
    flagShips = gamelogic.getVectorOfFlagShips();
    bullets = gamelogic.getVectorOfBullets();
}

void DisplayGame::startGame(RenderWindow& window , ScreenView & screenView)
{
    highScore = getHighScore();
    while ( window.isOpen() && screenView == GAME)
    {
        window.clear();
        window.draw(background);
        display.displayText(highScore, 50, Vector2f(750,100),window);
        if(gamelogic.getState() == GameState::Online)
        {
            screenConstants(window);
            pollforUserInput(window);
            gamelogic.gameLogic();
            getGameObjects();
            drawObjects.drawObjects(window,galaxians,galaxians2,flagShipEscorts,flagShips,bullets,galaxip);
        }
        else if (gamelogic.getState() == GameState::Paused) unPausegame(window);
        else endOfGame(window,screenView);
    }
}

void DisplayGame::pollforUserInput(RenderWindow& window)
{
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed) window.close();
        else if (event.type == Event::KeyPressed)
        {
            switch(event.key.code)
            {
            case Keyboard::Left:
                gamelogic.galaxipMoveleft();
                break;
            case Keyboard::Right:
                gamelogic.galaxipMoveRight();
                break;
            case Keyboard::LControl:
                gamelogic.shootGalaxipBullet();
                break;
            case Keyboard::Space:
                gamelogic.setState(Paused);
                break;
            case Keyboard::Escape:
                window.close();
            default:
                ;
            }
        }
    }
}

void DisplayGame::unPausegame(RenderWindow& window)
{
    Event gamePaused;
    while (window.pollEvent(gamePaused))
    {
        if (gamePaused.type == Event::KeyPressed)
        {
            if (gamePaused.key.code == Keyboard::Space)  gamelogic.setState(Online);
            if (gamePaused.key.code == Keyboard::Escape)  window.close();
        }
        showPausedWindow(window);
    }
}

void DisplayGame::showPausedWindow(RenderWindow& window)
{
    display.setTextColor(Color:: White);
    display.displayText("GAME PAUSED", 90, Vector2f (20,250),window);
    window.display();
}

string DisplayGame::convertToString(int Num)
{
    string Result;
    ostringstream convert;
    convert << Num;
    Result = convert.str();
    return Result;
}

string DisplayGame::getHighScore()
{
    string score;
    ifstream filereader("HighScore.txt");
    if (!filereader) throw logic_error("help.txt could not be opened");
    else getline(filereader, score);
    return score;
}

void DisplayGame::paintBackground()
{
    background.setTexture(texture);
    background.setColor(Color(255, 255, 255, 200));
    background.setPosition(0,0);
}

void DisplayGame::endOfGame(RenderWindow& window , ScreenView &screenView)
{
    display.setTextColor(Color:: Red);
    while (window.isOpen() && screenView == GAME)
    {
        window.clear();
        window.draw(background);
        win = gamelogic.youWin();
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();
            else if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Return && numOfLives != 1  && win == false)
                {
                    window.clear();
                    gamelogic.setState(Online);
                    numOfLives--;
                    startGame(window,screenView);
                }
                else if (event.key.code == Keyboard::Escape) window.close();
                else if (event.key.code == Keyboard::Return) screenView = MENU;
            }
        }
        if(numOfLives == 1 && win == false)
        {
            saveHighScore();
            display.displayText("GAME OVER", 50, Vector2f(50,200),window);
            display.displayText("YOU LOST", 60, Vector2f(200,350),window);
        }
        else if(numOfLives > 1 && win == false) display.displayText("TRY AGAIN", 100, Vector2f(100,300), window);
        else if(win == true)
        {
            saveHighScore();
            display.setTextColor(Color::Green);
            display.displayText("GAME OVER", 50, Vector2f(50,200),window);
            display.displayText("YOU WIN !", 100, Vector2f(200,350),window);
        }
        window.display();
    }
}
void DisplayGame::saveHighScore()
{
    ofstream ofile("HighScore.txt");
    int hScore;
    istringstream ( highScore ) >> hScore;
    if (score > hScore && ofile) ofile << score << endl;
    else if (ofile) ofile << highScore << endl;

}


