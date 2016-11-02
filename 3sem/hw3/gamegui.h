#pragma once

#include "game.h"

#include <QMainWindow>


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

    Game game;
};
