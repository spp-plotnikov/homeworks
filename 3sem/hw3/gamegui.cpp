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
    keyLeft->setKey(Qt::Key_Left);
    keyRight->setKey(Qt::Key_Right);

    connect(keyUp, SIGNAL(activated()), &game, SLOT(rotateCurrentCannonUp()));
    connect(keyDown, SIGNAL(activated()), &game, SLOT(rotateCurrentCannonDown()));
    connect(keyLeft, SIGNAL(activated()), &game, SLOT(moveCurrentCannonLeft()));
    connect(keyRight, SIGNAL(activated()), &game, SLOT(moveCurrentCannonRight()));
}


GameGUI::~GameGUI()
{
    delete keyRight;
    delete keyLeft;
    delete keyDown;
    delete keyUp;
    delete ui;
}
