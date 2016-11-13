#include "shot.h"

#include <QPoint>
#include <QtMath>
#include <QGraphicsScene>


void Shot::makeShot(bool rightSide)
{
    if (shootRightNow)
    {
        return;
    }
    shootRightNow = true;

    if (rightSide)
    {
        direction = 1;
    }
    else
    {
        direction = -1;
    }

    QPoint muzzle(60, 30);  //  the place where the bullets emerge
    x = sourceOfShot->mapToScene(muzzle).x();
    y = sourceOfShot->mapToScene(muzzle).y();

    double angle = 40 - sourceOfShot->rotation();   //  40 is angle of cannon in picture
    angle = qDegreesToRadians(angle);

    vx = v * qCos(angle);
    vy = v * qSin(angle);
    t = 0;

    sourceOfShot->scene()->addItem(bulletInScene);

    connect(&timer, SIGNAL(timeout()), this, SLOT(updatePos()));
    timer.start(20);

    updatePos();
}


void Shot::updatePos()
{
    t += 0.1f;

    const int shift = 20;   //  correction for GUI
    bulletInScene->setPos(x + t * vx * direction - shift, y - (vy - (g / 2) * t) * t - shift);

    if ((!(bulletInScene->collidesWithItem(sourceOfShot)))
            && bulletInScene->collidingItems().size() > 0
            || bulletInScene->x() < 0
            || bulletInScene->x() > sourceOfShot->scene()->width())
    {
        timer.stop();
        otherCannonCollisionCheck();
        bulletInScene->scene()->removeItem(bulletInScene);
        shootRightNow = false;
        disconnect(&timer, SIGNAL(timeout()), this, SLOT(updatePos()));
    }
}


Shot::~Shot()
{
    if (!shootRightNow)
    {
        delete bulletInScene;
    }
}
