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
    case blue:
    {
        cannon.convertFromImage(QImage(":/new/prefix1/images/cannons/blue-cannon.png").scaled(64, 64));
        break;
    }
    case gray:
    {
        cannon.convertFromImage(QImage(":/new/prefix1/images/cannons/gray-cannon.png").scaled(64, 64));
        break;
    }
    case orange:
    {
        cannon.convertFromImage(QImage(":/new/prefix1/images/cannons/orange-cannon.png").scaled(64, 64));
        break;
    }
    case purple:
    {
        cannon.convertFromImage(QImage(":/new/prefix1/images/cannons/purple-cannon.png").scaled(64, 64));
        break;
    }
    case red:
    {
        cannon.convertFromImage(QImage(":/new/prefix1/images/cannons/red-cannon.png").scaled(64, 64));
        break;
    }
    default:
    {
        cannon.convertFromImage(QImage(":/new/prefix1/images/cannons/black-cannon.png").scaled(64, 64));
    }
    }
    itemInScene = new QGraphicsPixmapItem(cannon);

    // (30, 50) is a pivot point (the centre of the wheel)
    itemInScene->setTransformOriginPoint(30, 50);

    if (shotType == littleBullet)
    {
        shotMaker = new LittleBulletShot(itemInScene);
    }
    else
    {
        shotMaker = new GrenadeShot(itemInScene);
    }

    const int objectName = 0;
    itemInScene->setData(objectName, "Cannon");
    ownerScene->addItem(itemInScene);
    setPosition(0);

    connect(shotMaker,SIGNAL(enemyIsDefeated()), this, SLOT(setWinner()));
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


void Cannon::setWinner()
{
    emit hasWon();
}


Cannon::~Cannon()
{
    delete shotMaker;
}
