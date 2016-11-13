#pragma once

#include <QMainWindow>
#include <QShortcut>

#include "./Network_Component/networkentity.h"
#include "./Game_Component/game.h"


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

private slots:
    void activateKeys();
    void deactivateKeys();
    void createClient();
    void createServer();
    void hideNetworkFeatures();

private:
    Ui::GameGUI *ui;

    QShortcut *keyUp = new QShortcut(this);
    QShortcut *keyDown = new QShortcut(this);
    QShortcut *keyLeft = new QShortcut(this);
    QShortcut *keyRight = new QShortcut(this);
    QShortcut *keyEnter = new QShortcut(this);

    Game game;

    NetworkEntity *networkEntity = nullptr;
};
