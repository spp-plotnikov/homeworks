#include <QFile>
#include <QString>
#include <QByteArray>
#include "clientspp.h"
#include "ui_clientspp.h"
#include "../helper/messengerhelper.h"


ClientSPP::ClientSPP(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientSPP)
{
    ui->setupUi(this);

    setFixedSize(420, 370);
    ui->sendButton->setIcon(QIcon(":new/prefix1/images/send1.png"));
    ui->tryToConnectButton->setIcon(QIcon(":new/prefix1/images/connect4.png"));
    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");

    connect(ui->tryToConnectButton, SIGNAL(clicked()), this, SLOT(connectToServer()));
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(sessionOpened()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(sessionClosed()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(acceptMessage()));
    connect(ui->newMessage, SIGNAL(textChanged()), this, SLOT(sendButtonAbility()));
}

ClientSPP::~ClientSPP()
{
    delete tcpSocket;
    delete ui;
}


//------------------------------------------------------------------


void ClientSPP::connectToServer()
{
    QFile port("../port.spp_file");
    port.open(QIODevice::ReadWrite | QIODevice::Text);
    QByteArray data = port.readAll();
    port.remove();

    tcpSocket->connectToHost("localhost", data.toInt());
}


void ClientSPP::sessionOpened()
{
    ui->sendButton->setEnabled(true);
    ui->tryToConnectButton->setEnabled(false);
    ui->chatText->append("Hurray!!! Connected! :-) \n");
}


void ClientSPP::sessionClosed()
{
    ui->sendButton->setEnabled(false);
    ui->tryToConnectButton->setEnabled(true);
    ui->chatText->append("Disconnected :-( \n");
}


void ClientSPP::sendMessage()
{
    MessengerHelper::sendMessage(tcpSocket, ui->newMessage->toPlainText());
    ui->chatText->append("Me: " + ui->newMessage->toPlainText());
    ui->newMessage->clear();
}


void ClientSPP::acceptMessage()
{
    QString message = MessengerHelper::acceptMessage(tcpSocket);
    ui->chatText->append("Server: " + message);
}


void ClientSPP::sendButtonAbility()
{
    if (ui->tryToConnectButton->isEnabled())
        return;
    ui->sendButton->setEnabled(!ui->newMessage->toPlainText().isEmpty());
}
