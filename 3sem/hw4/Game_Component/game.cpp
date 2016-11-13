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

    blackCannon = new Cannon(scene);
    redCannon = new Cannon(scene, Cannon::red, Cannon::grenade);
    redCannon->setPosition(300);
    currentCannon = blackCannon;
    whoIsEnemy = redCannon;

    connect(redCannon, SIGNAL(hasWon()), this, SLOT(announceWinner()));
    connect(blackCannon, SIGNAL(hasWon()), this, SLOT(announceWinner()));
}


QGraphicsScene* Game::getScene() const
{
    return scene;
}


void Game::changeCurrentCannon()
{
    if (currentCannon == blackCannon)
    {
        currentCannon = redCannon;
    }
    else
    {
        currentCannon = blackCannon;
    }

    if (currentCannon == whoIsEnemy)
    {
        emit sceneLocked();
    }
    else
    {
        emit sceneUnlocked();
    }
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
}


void Game::rotateCurrentCannonUp()
{
    currentCannon->rotateUp();
    emit currentCannonRotatedUp();
}


void Game::rotateCurrentCannonDown()
{
    currentCannon->rotateDown();
    emit currentCannonRotatedDown();
}


void Game::moveCurrentCannonLeft()
{
    currentCannon->moveLeft();
    emit currentCannonMovedLeft();
}


void Game::moveCurrentCannonRight()
{
    currentCannon->moveRight();
    emit currentCannonMovedRight();
}


void Game::shotCurrentCannon()
{
    currentCannon->shot();
    changeCurrentCannon();
    emit currentCannonShot();
}


void Game::announceWinner()
{
    const int fontSize = 48;
    const int x = 150;
    const int y = 100;

    QGraphicsTextItem *message = nullptr;
    if (currentCannon == whoIsEnemy)
    {
        message = new QGraphicsTextItem("You have won!");
        message->setDefaultTextColor(QColor(Qt::GlobalColor::darkGreen));
    }
    else
    {
        message = new QGraphicsTextItem("You lose!");
        message->setDefaultTextColor(QColor(Qt::GlobalColor::darkRed));
    }


    QFont font("Comic Sans MS");
    font.setPointSize(fontSize);
    font.setBold(true);
    message->setFont(font);
    message->setPos(x, y);
    scene->addItem(message);

    if (currentCannon != whoIsEnemy)
    {
        emit sceneLocked();
    }
}


Game::~Game()
{
    delete blackCannon;
    delete redCannon;
    delete scene;
}
