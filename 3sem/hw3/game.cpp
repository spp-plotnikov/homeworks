#include "game.h"

#include <QPixmap>
#include <QPolygon>


Game::Game(QObject *parent) : QObject(parent)
{
    setLandscape();

    blackCannon.addToScene(scene);
    listOfCannons.append(blackCannon);
    currentCannon = listOfCannons.begin();
}


QGraphicsScene* Game::getScene() const
{
    return scene;
}


void Game::setLandscape()
{
    // hard coded

    const int realWidth = 728;
    const int realHeight = 348;
    scene->setSceneRect(QRect(0, 0, realWidth, realHeight));

    QPolygon landscape;
    landscape << QPoint(0, realHeight)
              << QPoint(20, realHeight - 20)
              << QPoint(40, realHeight - 15)
              << QPoint(60, realHeight - 22)
              << QPoint(80, realHeight - 44)
              << QPoint(100, realHeight - 69)
              << QPoint(120, realHeight - 100)
              << QPoint(140, realHeight - 105)
              << QPoint(160, realHeight - 95)
              << QPoint(180, realHeight - 73)
              << QPoint(200, realHeight - 53)
              << QPoint(220, realHeight - 31)
              << QPoint(240, realHeight - 16)
              << QPoint(260, realHeight - 13)
              << QPoint(280, realHeight - 17)
              << QPoint(300, realHeight - 15)
              << QPoint(320, realHeight - 17)
              << QPoint(340, realHeight - 19)
              << QPoint(360, realHeight - 23)
              << QPoint(380, realHeight - 28)
              << QPoint(400, realHeight - 34)
              << QPoint(420, realHeight - 44)
              << QPoint(440, realHeight - 64)
              << QPoint(460, realHeight - 94)
              << QPoint(480, realHeight - 115)
              << QPoint(500, realHeight - 130)
              << QPoint(520, realHeight - 133)
              << QPoint(540, realHeight - 131)
              << QPoint(560, realHeight - 108)
              << QPoint(580, realHeight - 90)
              << QPoint(600, realHeight - 60)
              << QPoint(620, realHeight - 40)
              << QPoint(640, realHeight - 36)
              << QPoint(660, realHeight - 32)
              << QPoint(680, realHeight - 27)
              << QPoint(700, realHeight - 25)
              << QPoint(720, realHeight - 24)
              << QPoint(realWidth, realHeight - 22)
              << QPoint(realWidth, realHeight);


    scene->addPolygon(landscape, QPen(), QBrush(Qt::green));

    QPixmap sun;
    sun.convertFromImage(QImage(":/new/prefix1/sun.png").scaled(100, 100).mirrored(true, false));
    scene->addPixmap(sun);
}


void Game::rotateCurrentCannonUp()
{
    currentCannon->rotateUp();
}


void Game::rotateCurrentCannonDown()
{
    currentCannon->rotateDown();
}


void Game::moveCurrentCannonLeft()
{
    currentCannon->moveLeft();
}


void Game::moveCurrentCannonRight()
{
    currentCannon->moveRight();
}


Game::~Game()
{
    delete scene;
}
