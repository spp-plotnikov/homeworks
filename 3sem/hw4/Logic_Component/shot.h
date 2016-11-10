#pragma once

#include <QTimer>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>


/// \brief parent class for bullets for Cannon in Simple Scorched Earth game
/// \author © Sasha Plotnikov Production, Ltd.
class Shot : public QObject
{
    Q_OBJECT
public:
    void makeShot(bool  rightSide);
    ~Shot();

signals:
    void enemyIsDefeated();

private slots:
    void updatePos();

protected:
    QGraphicsItem *sourceOfShot;
    QGraphicsPixmapItem *bulletInScene;
    int v = 60;   ///< speed of the bullet

private:
    virtual void otherCannonCollisionCheck() = 0;

    QTimer timer;

    bool shootRightNow = false;

    // physical items:
    const int g = 10;   ///<  Gravitational acceleration
    int vx = 0;     ///< horisontal speed
    int vy = 0;     ///< vertical speed
    int x = 0;      ///< position of source cannon
    int y = 0;      ///< position of source cannon
    float t = 0;    ///<  time
    int direction = 1;  ///< 1 if right, -1 if left
};
