#pragma once

#include <QGraphicsPixmapItem>


class Cannon
{
public:
    enum CannonColour {Black, Blue, Gray, Orange, Purple, Red};

    Cannon(Cannon::CannonColour colour = Cannon::Black);
    QGraphicsPixmapItem* getPointer() const;
    void setPosition(int x, int y);
    ~Cannon();

private:
    QGraphicsPixmapItem *itemInScene = nullptr;
};
