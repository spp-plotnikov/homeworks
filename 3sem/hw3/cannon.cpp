#include "cannon.h"

#include <QPixmap>


Cannon::Cannon(CannonColour colour)
{
    QPixmap cannon;
    switch (colour)
    {
    case Blue:
    {
        cannon.convertFromImage(QImage(":/new/prefix1/cannons/blue-cannon.png").scaled(64, 64));
        break;
    }
    case Gray:
    {
        cannon.convertFromImage(QImage(":/new/prefix1/cannons/gray-cannon.png").scaled(64, 64));
        break;
    }
    case Orange:
    {
        cannon.convertFromImage(QImage(":/new/prefix1/cannons/orange-cannon.png").scaled(64, 64));
        break;
    }
    case Purple:
    {
        cannon.convertFromImage(QImage(":/new/prefix1/cannons/purple-cannon.png").scaled(64, 64));
        break;
    }
    case Red:
    {
        cannon.convertFromImage(QImage(":/new/prefix1/cannons/red-cannon.png").scaled(64, 64));
        break;
    }
    default:
    {
        cannon.convertFromImage(QImage(":/new/prefix1/cannons/black-cannon.png").scaled(64, 64));
    }
    }
    itemInScene = new QGraphicsPixmapItem(cannon);

    // (30, 50) is a pivot point (the centre of the wheel)
    itemInScene->setTransformOriginPoint(30, 50);
}


void Cannon::addToScene(QGraphicsScene *scene) const
{
    scene->addItem(itemInScene);
}


void Cannon::setPosition(int x, int y)
{
    itemInScene->setPos(x, y);
}


void Cannon::rotateUp()
{
    const int minAngle = -50;
    if (itemInScene->rotation() < minAngle)
        return;

    itemInScene->setRotation(itemInScene->rotation() - 3);
}


void Cannon::rotateDown()
{
    const int maxAngle = 0;
    if (itemInScene->rotation() > maxAngle)
        return;

    itemInScene->setRotation(itemInScene->rotation() + 3);
}


void Cannon::moveLeft()
{

}


void Cannon::moveRight()
{

}


Cannon::~Cannon()
{
    delete itemInScene;
}
