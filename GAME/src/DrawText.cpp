#include "DrawText.h"
#include <iostream>
//#include <iomanip>
//#include <locale>
#include <sstream>
//#include <string> // this should be already included in <sstream>

using namespace std;

DrawText::DrawText()
{
    font.loadFromFile("transformers_movie.ttf");
    color = Color::White;
}

void DrawText::setTextColor(Color newColor)
{
    color = newColor;
}
void DrawText::setFont(string newFont)
{
    font.loadFromFile(newFont);
}

void DrawText::displayText(string text, int textSize, Vector2f position, RenderWindow &window)
{
    Text textToBeDisplayed(text, font , textSize);
    textToBeDisplayed.setStyle(Text::Regular);
    textToBeDisplayed.setPosition(position);
    textToBeDisplayed.
    setColor(color);
    window.draw(textToBeDisplayed);
}
