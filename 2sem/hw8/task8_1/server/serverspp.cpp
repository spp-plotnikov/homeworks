#include "serverspp.h"
#include "ui_serverspp.h"

ServerSPP::ServerSPP(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerSPP)
{
    ui->setupUi(this);

    setFixedSize(420, 370);
    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");
    ui->sendButton->setIcon(QIcon(":new/prefix1/images/send1.png"));
}

ServerSPP::~ServerSPP()
{
    delete ui;
}
