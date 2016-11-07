#pragma once

#include "shot.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>


/// \brief class for representing cannons in  S P P  Simple Scorched Earth game
/// \author © Sasha Plotnikov Production, Ltd.
class Cannon
{
public:
    /// \brief You can create cannon of various colors
    enum CannonColour {Black, Blue, Gray, Orange, Purple, Red};
    /// \brief Your cannon can shoot a variety of ammo
    enum ShotType {LittleBullet, Grenade};

    Cannon(QGraphicsScene *ownerScene,
           Cannon::CannonColour colour = Cannon::Black,
           Cannon::ShotType shotType = Cannon::LittleBullet);

    /// \brief sets cannon in certain position (is within the scene)
    void setPosition(int x);
    /// \brief raises the muzzle of cannon
    void rotateUp();
    /// \brief downs the muzzle of cannon
    void rotateDown();
    /// \brief shifts to the right by a very small distance
    void moveRight();
    /// \brief shifts to the left by a very small distance
    void moveLeft();
    /// \brief shoots by certain bullet
    void shot();
    ~Cannon();

private:
    void findVerticalPositionOnLandscape();
    void reflect();

    QGraphicsPixmapItem *itemInScene = nullptr;
    QGraphicsScene *ownerScene = nullptr;
    bool isRightOrientation = true;
    Shot *shotMaker = nullptr;
};
