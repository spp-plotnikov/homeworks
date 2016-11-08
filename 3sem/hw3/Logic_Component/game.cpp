#include "game.h"

#include <QFile>
#include <QPixmap>
#include <QPolygon>
#include <QTextStream>


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
    const int realWidth = 728;
    const int realHeight = 348;
    scene->setSceneRect(QRect(0, 0, realWidth, realHeight));

    QPolygon landscape;

    QFile landscapeFile(":/new/prefix1/landscape.spp_lndscp");
    landscapeFile.open(QIODevice::ReadOnly);
    QTextStream in(&landscapeFile);
    int x = 0;
    int y = 0;
    int quantity = 0;
    in >> quantity;
    for (int i = 0; i < quantity; i++)
    {
        in >> x >> y;
        landscape << QPoint(x, y);
    }
    landscapeFile.close();

    scene->addPolygon(landscape, QPen(), QBrush(Qt::green));

    QPixmap sun;
    sun.convertFromImage(QImage(":/new/prefix1/images/sun.png").scaled(100, 100).mirrored(true, false));
    scene->addPixmap(sun);

    blackCannon = new Cannon(scene);
    listOfCannons.append(*blackCannon);
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


void Game::shotCurrentCannon()
{
    currentCannon->shot();
}


Game::~Game()
{
    //delete blackCannon;  QList deletes cannons contained in it

    delete scene;
}
