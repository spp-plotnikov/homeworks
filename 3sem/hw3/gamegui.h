#pragma once

#include "game.h"

#include <QMainWindow>
#include <QShortcut>


namespace Ui {
class GameGUI;
}

class GameGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameGUI(QWidget *parent = 0);
    ~GameGUI();

private:
    Ui::GameGUI *ui;

    QShortcut *keyUp = new QShortcut(this);
    QShortcut *keyDown = new QShortcut(this);

    Game game;
};
