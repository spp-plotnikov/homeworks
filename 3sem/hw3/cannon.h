#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>


class Cannon
{
public:
    enum CannonColour {Black, Blue, Gray, Orange, Purple, Red};

    Cannon(Cannon::CannonColour colour = Cannon::Black);
    void addToScene(QGraphicsScene *scene) const;
    void setPosition(int x, int y);
    void rotateUp();
    void rotateDown();
    void moveRight();
    void moveLeft();
    ~Cannon();

private:
    QGraphicsPixmapItem *itemInScene = nullptr;
};
