#include "clientspp.h"
#include "ui_clientspp.h"

ClientSPP::ClientSPP(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientSPP)
{
    ui->setupUi(this);

    setFixedSize(420, 370);
    ui->sendButton->setIcon(QIcon(":new/prefix1/images/send1.png"));
    ui->tryToConnectButton->setIcon(QIcon(":new/prefix1/images/connect4.png"));
    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");
}

ClientSPP::~ClientSPP()
{
    delete ui;
}
