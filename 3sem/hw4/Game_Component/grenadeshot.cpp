#include "grenadeshot.h"

#include <QList>
#include <QRect>
#include <QPixmap>
#include <QGraphicsScene>


GrenadeShot::GrenadeShot(QGraphicsItem *sourceOfTheShot)
{
    sourceOfShot = sourceOfTheShot;
    QPixmap bullet;
    bullet.convertFromImage(QImage(":/new/prefix1/images/bomb.png").scaled(40, 40));
    bulletInScene = new QGraphicsPixmapItem(bullet);

    v = speed;
}


void GrenadeShot::otherCannonCollisionCheck()
{
    const int objectName = 0;
    const int radius = 80;
    QRect rect(bulletInScene->pos().x() - radius,
               bulletInScene->pos().y() - radius, 2 * radius, 2 * radius);
    QList<QGraphicsItem*> itemsInRect(bulletInScene->scene()->items(rect));

    for (int i = 0; i < itemsInRect.size(); i++)
    {
        if (itemsInRect.at(i)->data(objectName).toString() == "Cannon" &&
            itemsInRect.at(i) != sourceOfShot)
        {
            QPixmap bang;
            bang.convertFromImage(QImage(":/new/prefix1/images/bang.png").scaled(95, 95));
            QGraphicsItem *bigBang = new QGraphicsPixmapItem(bang);
            bigBang->setPos(itemsInRect.at(i)->pos());
            sourceOfShot->scene()->addItem(bigBang);
            emit enemyIsDefeated();
        }
    }
}
