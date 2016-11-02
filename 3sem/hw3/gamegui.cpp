#include "gamegui.h"
#include "ui_gamegui.h"


GameGUI::GameGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameGUI)
{
    ui->setupUi(this);

    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");
    statusBar()->setEnabled(false);
    setWindowIcon(QIcon(":/new/prefix1/logoSPP.ico"));

    ui->gameField->setScene(game.getScene());
}


GameGUI::~GameGUI()
{
    delete ui;
}
