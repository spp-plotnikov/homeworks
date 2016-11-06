#include "littlebulletshot.h"

#include <QDebug>
#include <QTimer>
#include <QtMath>
#include <QPixmap>
#include <QGraphicsScene>


void LittleBulletShot::makeShot(QGraphicsItem *sourceOfShot)
{
    const int x = sourceOfShot->x() + sourceOfShot->transformOriginPoint().x();
    const int y = sourceOfShot->y() + sourceOfShot->transformOriginPoint().y();

    double angle = 40 - sourceOfShot->rotation();   //  40 is angle of cannon in picture
    angle = qDegreesToRadians(angle);

    const int v = 60;   // speed 60 m/s
    const int vx = v * qCos(angle);
    const int vy = v * qSin(angle);
    const int g = 10;   //  Gravitational acceleration

    QPixmap bullet;
    bullet.convertFromImage(QImage(":/new/prefix1/bang.png").scaled(30, 30));
    bulletInScene = new QGraphicsPixmapItem(bullet);
    sourceOfShot->scene()->addItem(bulletInScene);

    int t = 0;  //  time
    QTimer timer(this);
    connect(&timer, SIGNAL(timeout()), this, SLOT(updatePos()));
    timer.start(1000);
    //
    bulletInScene->setPos(110, 110);
    //
    while (true)
    {
        if (positionUpdated)
        {
            currentPos.setX(x + t * vx);
            currentPos.setY(y - (t * vy - (g / 2) * t * t));
            positionUpdated = false;
        }
        t++;
qDebug() << t << currentPos.x() << currentPos.y();
        if ((!(bulletInScene->collidesWithItem(sourceOfShot))) && bulletInScene->collidingItems().size() > 0)
        {
            break;
        }
    }
    delete bulletInScene;
}


void LittleBulletShot::updatePos()
{
    qDebug() << "I'm here";
    bulletInScene->setPos(currentPos);
    positionUpdated = true;
}
