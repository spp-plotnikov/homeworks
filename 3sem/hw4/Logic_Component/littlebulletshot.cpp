#include "littlebulletshot.h"

#include <QList>
#include <QPixmap>
#include <QGraphicsScene>


LittleBulletShot::LittleBulletShot(QGraphicsItem *sourceOfTheShot)
{
    sourceOfShot = sourceOfTheShot;
    QPixmap bullet;
    bullet.convertFromImage(QImage(":/new/prefix1/images/bang.png").scaled(30, 30));
    bulletInScene = new QGraphicsPixmapItem(bullet);
}


void LittleBulletShot::otherCannonCollisionCheck()
{
    const int objectName = 0;
    QList<QGraphicsItem*> collidingItems(bulletInScene->collidingItems());
    for (int i = 0; i < collidingItems.size(); i++)
    {
        if (collidingItems.at(i)->data(objectName).toString() == "Cannon" &&
            collidingItems.at(i) != sourceOfShot)
        {
            QPixmap bang;
            bang.convertFromImage(QImage(":/new/prefix1/images/bang.png").scaled(90, 90));
            QGraphicsItem *bigBang = new QGraphicsPixmapItem(bang);
            bigBang->setPos(collidingItems.at(i)->pos());
            sourceOfShot->scene()->addItem(bigBang);
            emit enemyIsDefeated();
        }
    }
}
