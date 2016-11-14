#pragma once

#include "shot.h"

#include <QObject>



/// \brief child of parent class Shot, represents little bullet
/// \author © Sasha Plotnikov Production, Ltd.
class LittleBulletShot : public Shot
{
    Q_OBJECT
public:
    LittleBulletShot(QGraphicsItem *sourceOfTheShot);

private:
    void otherCannonCollisionCheck();
};
