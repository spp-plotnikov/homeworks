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

    keyUp->setKey(Qt::Key_Up);
    keyDown->setKey(Qt::Key_Down);
    connect(keyUp, SIGNAL(activated()), &game, SLOT(rotateCurrentCannonUp()));
    connect(keyDown, SIGNAL(activated()), &game, SLOT(rotateCurrentCannonDown()));
}


GameGUI::~GameGUI()
{
    delete keyDown;
    delete keyUp;
    delete ui;
}
