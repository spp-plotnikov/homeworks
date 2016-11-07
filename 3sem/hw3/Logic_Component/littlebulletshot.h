#pragma once

#include "shot.h"

#include <QTimer>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>


/// \brief implementation of abstract class Shot
/// \author © Sasha Plotnikov Production, Ltd.
class LittleBulletShot : public Shot
{
    Q_OBJECT
public:
    LittleBulletShot(QGraphicsItem *sourceOfShot);
    void makeShot(bool  rightSide);

private slots:
    void updatePos();

private:
    QTimer timer;
    QGraphicsItem *sourceOfShot;
    QGraphicsPixmapItem *bulletInScene;

    bool shootRightNow = false;

    // phisical items:
    const int v = 60;   ///< speed 60 m/s
    const int g = 10;   ///<  Gravitational acceleration
    int vx = 0;     ///< horisontal speed
    int vy = 0;     ///< vertical speed
    int x = 0;      ///< position of source cannon
    int y = 0;      ///< position of source cannon
    float t = 0;    ///<  time
    int direction = 1;  ///< 1 if right, -1 if left
};
