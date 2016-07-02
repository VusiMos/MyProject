#include "DrawObjects.h"

DrawObjects::DrawObjects() {}

void DrawObjects::drawObjects(RenderWindow& window,VecOfGalaxians galaxians,VecOfGalaxians galaxians2,VecOfGalaxians flagShipEscorts,VecOfGalaxians flagShips,vector <BulletPtr> bullets, Galaxip galaxip)
{
    texture.loadFromFile("missile.png");
    drawShip(texture, 710, 620, window);

    texture.loadFromFile("galaxian_1.png");
    drawGalaxians(galaxians,window);

    texture.loadFromFile("galaxian_2.png");
    drawGalaxians(galaxians2,window);

    texture.loadFromFile("flagship_escort.png");
    drawGalaxians(flagShipEscorts,window);

    texture.loadFromFile("flagship.png");
    drawGalaxians(flagShips,window);

    drawBullets(window, bullets);

    texture.loadFromFile("galaxip.png");
    drawShip(texture,galaxip.getXpos(),galaxip.getYpos(), window );
    window.display();
}


void DrawObjects::drawGalaxians(VecOfGalaxians galaxians, RenderWindow& window)
{
    for (auto iter=begin(galaxians); iter!=end(galaxians); ++iter)
        if((*iter)->isAlive()||(*iter)->isDiving()) drawShip(texture,(*iter)->getXpos(),(*iter)->getYpos(), window);
}

void DrawObjects::drawShip(Texture texture, float x, float y, RenderWindow& window)
{
    Sprite  ship;
    ship.setTexture(texture);
    ship.setTextureRect(IntRect(0, 0, 71, 98));
    ship.setColor(Color(255, 255, 255, 200));
    ship.setPosition(x,y);
    ship.scale(0.4, 0.4);
    window.draw(ship);
}

void DrawObjects::drawBullets(RenderWindow& window, vector <BulletPtr> bullets)
{
    for (auto iter=begin(bullets); iter!=end(bullets); ++iter)
        if((*iter)->getDirection() == DOWN && (*iter)->isAlive())
        {
            color = Color::Red;
            drawBullet((*iter)->getXpos(),(*iter)->getYpos(),window);
        }
        else if ((*iter)->getDirection() == UP && (*iter)->isAlive())
        {
            color = Color::White;
            drawBullet((*iter)->getXpos(),(*iter)->getYpos(),window);
        }
}

void DrawObjects::drawBullet(float x, float y, RenderWindow& window)
{
    CircleShape bullet;
    bullet.setRadius(3.f);
    bullet.setFillColor(color);
    bullet.setPosition(x,y);
    window.draw(bullet);
}
