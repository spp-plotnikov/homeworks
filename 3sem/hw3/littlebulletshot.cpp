#include "littlebulletshot.h"

#include <QDebug>
#include <QtMath>
#include <QPixmap>
#include <QGraphicsScene>


LittleBulletShot::LittleBulletShot(QGraphicsItem *sourceOfShot) :
    sourceOfShot(sourceOfShot)
{
}


void LittleBulletShot::makeShot()
{
    if (shootRightNow)
    {
        return;
    }
    shootRightNow = true;

    x = sourceOfShot->x() + sourceOfShot->transformOriginPoint().x();
    y = sourceOfShot->y() + sourceOfShot->transformOriginPoint().y();

    double angle = 40 - sourceOfShot->rotation();   //  40 is angle of cannon in picture
    angle = qDegreesToRadians(angle);

    vx = v * qCos(angle);
    vy = v * qSin(angle);
    t = 0;


    QPixmap bullet;
    bullet.convertFromImage(QImage(":/new/prefix1/bang.png").scaled(30, 30));
    bulletInScene = new QGraphicsPixmapItem(bullet);
    sourceOfShot->scene()->addItem(bulletInScene);
    updatePos();

    connect(&timer, SIGNAL(timeout()), this, SLOT(updatePos()));
    timer.start(20);
}


void LittleBulletShot::updatePos()
{
    t += 0.1f;

    const int shift = 20;   //  correction for GUI
    bulletInScene->setPos(x + t * vx - shift, y - (t * vy - (g / 2) * t * t) - shift);

    if ((!(bulletInScene->collidesWithItem(sourceOfShot))) && bulletInScene->collidingItems().size() > 0)
    {
        timer.stop();
        delete bulletInScene;
        shootRightNow = false;
        disconnect(&timer, SIGNAL(timeout()), this, SLOT(updatePos()));
    }
}
