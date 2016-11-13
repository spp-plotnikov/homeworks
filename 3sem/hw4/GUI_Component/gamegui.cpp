#include "gamegui.h"
#include "ui_gamegui.h"
#include "./Network_Component/client.h"
#include "./Network_Component/server.h"


GameGUI::GameGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameGUI)
{
    ui->setupUi(this);

    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");
    statusBar()->setEnabled(false);
    setWindowIcon(QIcon(":/new/prefix1/images/logoSPP.ico"));
    ui->clientButton->setIcon(QIcon(":/new/prefix1/images/client.png"));
    ui->serverButton->setIcon(QIcon(":/new/prefix1/images/server.png"));
    ui->connectButton->setIcon(QIcon(":/new/prefix1/images/connect.png"));
    ui->connectButton->setVisible(false);

    ui->gameField->setScene(game->getScene());

    keyUp->setKey(Qt::Key_Up);
    keyDown->setKey(Qt::Key_Down);
    keyLeft->setKey(Qt::Key_Left);
    keyRight->setKey(Qt::Key_Right);
    keyEnter->setKey(Qt::Key_Return);

    activateKeys();

    connect(ui->clientButton, SIGNAL(clicked(bool)), ui->connectButton, SLOT(show()));
    connect(ui->clientButton, SIGNAL(clicked(bool)), this, SLOT(createClient()));
    connect(ui->clientButton, SIGNAL(clicked(bool)), ui->serverButton, SLOT(setEnabled(bool)));
    connect(ui->serverButton, SIGNAL(clicked(bool)), ui->clientButton, SLOT(setEnabled(bool)));
    connect(ui->serverButton, SIGNAL(clicked(bool)), this, SLOT(createServer()));

    connect(game, SIGNAL(sceneLocked()), this, SLOT(deactivateKeys()));
    connect(game, SIGNAL(sceneUnlocked()), this, SLOT(activateKeys()));
}


void GameGUI::activateKeys()
{
    connect(keyUp, SIGNAL(activated()), game, SLOT(rotateCurrentCannonUp()));
    connect(keyDown, SIGNAL(activated()), game, SLOT(rotateCurrentCannonDown()));
    connect(keyLeft, SIGNAL(activated()), game, SLOT(moveCurrentCannonLeft()));
    connect(keyRight, SIGNAL(activated()), game, SLOT(moveCurrentCannonRight()));
    connect(keyEnter, SIGNAL(activated()), game, SLOT(shotCurrentCannon()));
}


void GameGUI::deactivateKeys()
{
    disconnect(keyUp, SIGNAL(activated()), game, SLOT(rotateCurrentCannonUp()));
    disconnect(keyDown, SIGNAL(activated()), game, SLOT(rotateCurrentCannonDown()));
    disconnect(keyLeft, SIGNAL(activated()), game, SLOT(moveCurrentCannonLeft()));
    disconnect(keyRight, SIGNAL(activated()), game, SLOT(moveCurrentCannonRight()));
    disconnect(keyEnter, SIGNAL(activated()), game, SLOT(shotCurrentCannon()));
}


void GameGUI::createClient()
{
    disconnect(ui->clientButton, SIGNAL(clicked(bool)), this, SLOT(createClient()));
    networkEntity = new Client(game);
    connect(ui->connectButton, SIGNAL(clicked(bool)), networkEntity, SLOT(connectToServer()));
    connect(networkEntity, SIGNAL(connectedToOtherNetworkEntity()), this, SLOT(hideNetworkFeatures()));
}


void GameGUI::createServer()
{
    disconnect(ui->serverButton, SIGNAL(clicked(bool)), this, SLOT(createServer()));
    game->changeEnemy();
    networkEntity = new Server(game);
    connect(networkEntity, SIGNAL(connectedToOtherNetworkEntity()), this, SLOT(hideNetworkFeatures()));
}


void GameGUI::hideNetworkFeatures()
{
    ui->line->setVisible(false);
    ui->connectButton->setVisible(false);
    ui->serverButton->setVisible(false);
    ui->clientButton->setVisible(false);
    setFixedHeight(400);
}


GameGUI::~GameGUI()
{
    if (networkEntity)
    {
        delete networkEntity;
    }
    delete keyEnter;
    delete keyRight;
    delete keyLeft;
    delete keyDown;
    delete keyUp;
    delete game;
    delete ui;
}
