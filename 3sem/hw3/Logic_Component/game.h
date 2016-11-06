#pragma once

#include "cannon.h"

#include <QGraphicsScene>
#include <QObject>
#include <QList>


class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);
    QGraphicsScene* getScene() const;
    ~Game();

private slots:
    void rotateCurrentCannonUp();
    void rotateCurrentCannonDown();
    void moveCurrentCannonRight();
    void moveCurrentCannonLeft();
    void shotCurrentCannon();

private:
    /// \attention This method contains hardcode
    void setLandscape();

    QGraphicsScene *scene = new QGraphicsScene();
    QList<Cannon> listOfCannons;
    QList<Cannon>::iterator currentCannon;
    Cannon blackCannon;
};
