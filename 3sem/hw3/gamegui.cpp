#include "gamegui.h"
#include "ui_gamegui.h"

#include <QGraphicsEllipseItem>

GameGUI::GameGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameGUI)
{
    ui->setupUi(this);

    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");
    statusBar()->setEnabled(false);
    setWindowIcon(QIcon(":/new/prefix1/logoSPP.ico"));

    ui->gameField->setScene(scene);

    //

    QGraphicsItem *ellips = new QGraphicsEllipseItem(0, 0, 20, 70);

    scene->addItem(ellips);
}

GameGUI::~GameGUI()
{
    delete scene;
    delete ui;
}
