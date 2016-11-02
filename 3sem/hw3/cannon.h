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
    ~Cannon();

private:
    QGraphicsPixmapItem *itemInScene = nullptr;
};
