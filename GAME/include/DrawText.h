#ifndef DISPLAY_H
#define DISPLAY_H
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GameBase.h"
#include <cstring>
#include <iostream>

using namespace sf;
using namespace std;


class DrawText
{
public:
    /** \brief Default constructor
     *
     * Initialises the text font and colour.
     */
    DrawText();
    /** \brief Draws the text given to the window at the specified position and size.
     *
     * \param text string
     * \param textSize int
     * \param position Vector2f
     * \param window RenderWindow&
     */
    void displayText(string, int, Vector2f, RenderWindow &);
    /** \brief Changes the color of the text
     *
     * \param color Color
     */
    void setTextColor(Color);
    /** \brief Changes the font of the text
     *
     * \param newFont string
     */
    void setFont(string);

private:
    Font font;
    Color color;
    Texture texture;
};

#endif // DISPLAY_H
