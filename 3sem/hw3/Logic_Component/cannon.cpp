#include "cannon.h"
#include "grenadeshot.h"
#include "littlebulletshot.h"

#include <QPixmap>
#include <QTransform>


Cannon::Cannon(QGraphicsScene *ownerScene, Cannon::CannonColour colour, Cannon::ShotType shotType) :
    ownerScene(ownerScene)
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

    if (shotType == LittleBullet)
    {
        shotMaker = new LittleBulletShot(itemInScene);
    }
    else
    {
        shotMaker = new GrenadeShot();
    }

    ownerScene->addItem(itemInScene);
    setPosition(0);
}


void Cannon::setPosition(int x)
{
    const int realMaxWidth = ownerScene->width() - itemInScene->boundingRect().width();
    if (x < 0 || x > realMaxWidth)
        return;

    itemInScene->setX(x);
    findVerticalPositionOnLandscape();
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
    if (isRightOrientation)
    {
        isRightOrientation = false;
        reflect();
    }

    setPosition(itemInScene->x() - 3);
}


void Cannon::moveRight()
{
    if (!isRightOrientation)
    {
        isRightOrientation = true;
        reflect();
    }

    setPosition(itemInScene->x() + 3);
}


void Cannon::findVerticalPositionOnLandscape()
{
    qreal y = itemInScene->y();
    if (y == 0)
    {
        y = (ownerScene->height()) / 2;
        itemInScene->setY(y);
    }

    if (itemInScene->collidingItems().size() > 0)
    {
        while (itemInScene->collidingItems().size() > 0)
        {
            y--;
            itemInScene->setY(y);
        }
    }
    else
    {
        while (itemInScene->collidingItems().size() == 0)
        {
            y++;
            itemInScene->setY(y);
        }
    }
}


void Cannon::reflect()
{
    QTransform mirroring;
    mirroring.scale(-1, 1);
    mirroring.translate(-(itemInScene->boundingRect().width()), 0);
    itemInScene->setTransform(mirroring, true);
}


void Cannon::shot()
{
    shotMaker->makeShot(isRightOrientation);
}


Cannon::~Cannon()
{
    delete shotMaker;
    delete itemInScene;
}
