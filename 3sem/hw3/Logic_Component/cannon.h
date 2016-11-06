#pragma once

#include "shot.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>


class Cannon
{
public:
    enum CannonColour {Black, Blue, Gray, Orange, Purple, Red};
    enum ShotType {LittleBullet, Grenade};

    Cannon(Cannon::CannonColour colour = Cannon::Black, Cannon::ShotType shotType = Cannon::LittleBullet);
    void addToScene(QGraphicsScene *scene);

    /// \warning the following methods work only after setting the scene
    void setPosition(int x);
    void rotateUp();
    void rotateDown();
    void moveRight();
    void moveLeft();
    void shot();
    ~Cannon();

private:
    void findVerticalPositionOnLandscape();
    void reflect();

    QGraphicsPixmapItem *itemInScene = nullptr;
    bool isRightOrientation = true;
    Shot *shotMaker = nullptr;
};
