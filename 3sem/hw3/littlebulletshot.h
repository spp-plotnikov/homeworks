#pragma once

#include "shot.h"

#include <QPoint>
#include <QObject>
#include <QGraphicsPixmapItem>


class LittleBulletShot : public Shot
{
    Q_OBJECT
public:
    void makeShot(QGraphicsItem *sourceOfShot);

private slots:
    void updatePos();

private:
    QPoint currentPos;
    bool positionUpdated;
    QGraphicsPixmapItem *bulletInScene;
};
