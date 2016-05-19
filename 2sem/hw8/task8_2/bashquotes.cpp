#include "bashquotes.h"
#include "ui_bashquotes.h"

BashQuotes::BashQuotes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BashQuotes)
{
    ui->setupUi(this);
    ui->increaseRating->setIcon(QIcon(":new/prefix1/images/plus.png"));
    ui->decreaseRating->setIcon(QIcon(":new/prefix1/images/minus.png"));
    ui->bayan->setIcon(QIcon(":new/prefix1/images/bayan2.png"));
    ui->load->setIcon(QIcon(":new/prefix1/images/load.png"));
    ui->next->setIcon(QIcon(":new/prefix1/images/next1.png"));
    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");
}

BashQuotes::~BashQuotes()
{
    delete ui;
}
