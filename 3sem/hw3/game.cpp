#include "game.h"

#include <QPixmap>
#include <QPolygon>


Game::Game(QObject *parent) : QObject(parent)
{
    setLandscape();
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
              << QPoint(280, realHeight - 17);

    scene->addPolygon(landscape, QPen(), QBrush(Qt::green));

    QPixmap sun;
    sun.convertFromImage(QImage(":/new/prefix1/sun.png").scaled(100, 100).mirrored(true, false));
    scene->addPixmap(sun);
////
////
////

//    Cannon *blackCannon = new Cannon();
////    blackCannon->setPosition(100, 100);
//    blackCannon->addToScene(scene);
//    blackCannon->setPosition(100, 100);

//    Cannon *redCannon = new Cannon(Cannon::Red);
//    redCannon->addToScene(scene);
//    redCannon->setPosition(100, 100);
//    //delete redCannon
////    blackCannon->setPosition(100, 250);

//    //delete blackCannon


    blackCannon.addToScene(scene);
    listOfCannons.append(blackCannon);
    currentCannon = listOfCannons.begin();
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
