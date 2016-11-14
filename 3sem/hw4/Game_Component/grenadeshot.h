#pragma once

#include "shot.h"

#include <QObject>



/// \brief child of parent class Shot, represents big gtenade bang
/// \author © Sasha Plotnikov Production, Ltd.
class GrenadeShot : public Shot
{
    Q_OBJECT
public:
    GrenadeShot(QGraphicsItem *sourceOfTheShot);

private:
    void otherCannonCollisionCheck();

    int speed = 70;
};
