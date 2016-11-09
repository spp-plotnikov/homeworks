#pragma once

#include <QGraphicsItem>
#include <QObject>


/// \brief parent class for bullets for Cannon in Simple Scorched Earth game
/// \author © Sasha Plotnikov Production, Ltd.
class Shot : public QObject
{
    Q_OBJECT
public:
    virtual void makeShot(bool  rightSide) = 0;

signals:
    void enemyIsDefeated();
};
