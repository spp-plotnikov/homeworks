#pragma once

#include "./Logic_Component/game.h"

#include <QMainWindow>
#include <QShortcut>


namespace Ui {
class GameGUI;
}

/// \brief class for GUI of  S P P  Simple Scorched Earth game
/// \author © Sasha Plotnikov Production, Ltd.
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
    QShortcut *keyLeft = new QShortcut(this);
    QShortcut *keyRight = new QShortcut(this);
    QShortcut *keyEnter = new QShortcut(this);

    Game game;
};
