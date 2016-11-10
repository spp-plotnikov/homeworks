#include "gamegui.h"
#include "ui_gamegui.h"


GameGUI::GameGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameGUI)
{
    ui->setupUi(this);

    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");
    statusBar()->setEnabled(false);
    setWindowIcon(QIcon(":/new/prefix1/images/logoSPP.ico"));

    ui->gameField->setScene(game.getScene());

    keyUp->setKey(Qt::Key_Up);
    keyDown->setKey(Qt::Key_Down);
    keyLeft->setKey(Qt::Key_Left);
    keyRight->setKey(Qt::Key_Right);
    keyEnter->setKey(Qt::Key_Return);

    activateKeys();

    connect(&game, SIGNAL(sceneLocked()), this, SLOT(deactivateKeys()));
    connect(&game, SIGNAL(sceneUnlocked()), this, SLOT(activateKeys()));
}


void GameGUI::activateKeys()
{
    connect(keyUp, SIGNAL(activated()), &game, SLOT(rotateCurrentCannonUp()));
    connect(keyDown, SIGNAL(activated()), &game, SLOT(rotateCurrentCannonDown()));
    connect(keyLeft, SIGNAL(activated()), &game, SLOT(moveCurrentCannonLeft()));
    connect(keyRight, SIGNAL(activated()), &game, SLOT(moveCurrentCannonRight()));
    connect(keyEnter, SIGNAL(activated()), &game, SLOT(shotCurrentCannon()));
}


void GameGUI::deactivateKeys()
{
    disconnect(keyUp, SIGNAL(activated()), &game, SLOT(rotateCurrentCannonUp()));
    disconnect(keyDown, SIGNAL(activated()), &game, SLOT(rotateCurrentCannonDown()));
    disconnect(keyLeft, SIGNAL(activated()), &game, SLOT(moveCurrentCannonLeft()));
    disconnect(keyRight, SIGNAL(activated()), &game, SLOT(moveCurrentCannonRight()));
    disconnect(keyEnter, SIGNAL(activated()), &game, SLOT(shotCurrentCannon()));
}


GameGUI::~GameGUI()
{
    delete keyEnter;
    delete keyRight;
    delete keyLeft;
    delete keyDown;
    delete keyUp;
    delete ui;
}
