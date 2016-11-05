#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>


class Cannon
{
public:
    enum CannonColour {Black, Blue, Gray, Orange, Purple, Red};

    Cannon(Cannon::CannonColour colour = Cannon::Black);
    void addToScene(QGraphicsScene *scene);
    void setPosition(int x);
    void rotateUp();
    void rotateDown();
    void moveRight();
    void moveLeft();
    ~Cannon();

private:
    void findVerticalPositionOnLandscape();
    void reflect();

    QGraphicsPixmapItem *itemInScene = nullptr;
    bool isRightOrientation = true;
};
