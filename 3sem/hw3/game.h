#pragma once

#include <QGraphicsScene>


class Game
{
public:
    Game();
    QGraphicsScene* getScene() const;
    ~Game();

private:
    /// \attention This method contains hardcode
    void setLandscape();

    QGraphicsScene *scene = new QGraphicsScene();
};
