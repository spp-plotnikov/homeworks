#pragma once

#include "cannon.h"

#include <QGraphicsScene>
#include <QObject>


/// \brief main class of Simple Scorched Earth game
/// \author © Sasha Plotnikov Production, Ltd.
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
    void announceWinner();

private:
    void setLandscape();

    QGraphicsScene *scene = new QGraphicsScene();
    Cannon *currentCannon = nullptr;
    Cannon *blackCannon = nullptr;
    Cannon *redCannon = nullptr;
};
