#include "game.h"

#include <QFont>
#include <QFile>
#include <QPixmap>
#include <QPolygon>
#include <QTextStream>
#include <QGraphicsTextItem>


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
    redCannon = new Cannon(scene, Cannon::red);
    redCannon->setPosition(300);
    currentCannon = blackCannon;
    connect(currentCannon, SIGNAL(hasWon()), this, SLOT(announceWinner()));
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


void Game::announceWinner()
{
    const int fontSize = 48;
    const int x = 150;
    const int y = 100;

    QGraphicsTextItem *message = new QGraphicsTextItem("You have won!");
    QFont font("Comic Sans MS");
    font.setPointSize(fontSize);
    font.setBold(true);
    message->setFont(font);
    message->setDefaultTextColor(QColor(Qt::GlobalColor::darkGreen));
    message->setPos(x, y);
    scene->addItem(message);
}


Game::~Game()
{
    delete blackCannon;
    delete redCannon;
    delete scene;
}
