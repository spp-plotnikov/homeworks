#include "bashquotes.h"
#include "ui_bashquotes.h"

BashQuotes::BashQuotes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BashQuotes)
{
    ui->setupUi(this);
    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");
}

BashQuotes::~BashQuotes()
{
    delete ui;
}
