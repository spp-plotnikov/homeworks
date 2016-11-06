#pragma once

#include <QGraphicsItem>
#include <QObject>


class Shot : public QObject
{
    Q_OBJECT
public:
    virtual void makeShot() = 0;
};
