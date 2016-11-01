#pragma once

#include <QMainWindow>
#include <QGraphicsScene>


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
    /// \attention This method contains hardcode
    void setLandscape();

    Ui::GameGUI *ui;

    QGraphicsScene *scene = new QGraphicsScene();
};
