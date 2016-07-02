#include "GameBase.h"
#include <iostream>

using namespace std;

GameBase::GameBase()
{
    createGalaxians();
    getGalaxianVectors();
    state = Online;
    win = false;
    score = 0;
}

void GameBase::setState(GameState gameState)
{
    state = gameState;
}
void GameBase::galaxipMoveleft()
{
    galaxip.moveLeft();
}
void GameBase::galaxipMoveRight()
{
    galaxip.moveRight();
}
void GameBase::createGalaxians()
{
    galaxianController.createGalaxians();
}

void GameBase::shootGalaxipBullet()
{
    bulletsController.add(galaxip.getXpos(), galaxip.getYpos(), UP);

}

void GameBase::shootGalaxianBullet(vector <Position> positions)
{
    for (auto position : positions)
        bulletsController.add(position.at(0), position.at(1), DOWN);
}

void GameBase::getGalaxianVectors()
{
    galaxians = galaxianController.getVectorOfGalaxians();
    galaxians2 = galaxianController.getVectorOfGalaxians2();
    flagShipEscorts =  galaxianController.getVectorOfFlagShipEscorts();
    flagShips = galaxianController.getVectorOfFlagShips();
}
void GameBase::setGalaxianVectors()
{
    galaxianController.setVectorOfGalaxians(galaxians);
    galaxianController.setVectorOfGalaxians2(galaxians2);
    galaxianController.setVectorOfFlagShipEscorts(flagShipEscorts);
    galaxianController.setVectorOfFlagShips(flagShips);
}

void GameBase::gameLogic()
{
    galaxianController.update();
    getGalaxianVectors();
    shootGalaxianBullet(galaxianController.getBulletPositions());
    bulletsController.update();
    bullets = bulletsController.getBullets();
    CollisionDetector col;
    col.checkCollisions(galaxians,galaxians2,flagShipEscorts,flagShips,bullets,galaxip);
    score += col.getScore();
    if(col.isGameOver() || allGalaxiansDead())
    {
        bullets.clear();
        returnDivingToFormation();
        state = GameOver;
        if(allGalaxiansDead()) win = true;
    }
    bulletsController.setBullets(bullets);
    setGalaxianVectors();
}

void GameBase::returnDivingToFormation()
{
    for (auto galaxian : galaxians)
        if (galaxian->isDiving())galaxian->setState(ALIVE);
    for (auto galaxian : galaxians2)
        if (galaxian->isDiving())galaxian->setState(ALIVE);
    for (auto galaxian : flagShipEscorts)
        if (galaxian->isDiving())galaxian->setState(ALIVE);
    for (auto galaxian : flagShips)
        if (galaxian->isDiving())galaxian->setState(ALIVE);
}

bool GameBase::allGalaxiansDead()
{
    if(galaxians.size()==0 && galaxians2.size()==0 && flagShips.size()==0 && flagShipEscorts.size()==0)
        return true;
    return false;
}
