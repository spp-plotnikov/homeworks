#include <QSignalMapper>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");

    QSignalMapper *forPrinting = new QSignalMapper(this);
    foreach  (QPushButton *button, this->findChildren<QPushButton*>())
    {
        if (button->text() != "C" && button->text() != "←" && button->text() != "=")
        {
            forPrinting->setMapping(button, button->text());
            connect(button, SIGNAL(clicked()), forPrinting, SLOT(map()));
        }
    }

    connect(forPrinting, SIGNAL(mapped(const QString &)),
        this, SLOT(printExpression(const QString &)));
}


void MainWindow::printExpression(const QString &text)
{
    ui->expression->setText(text);
}


MainWindow::~MainWindow()
{
    delete ui;
}
