#include <QSignalMapper>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");

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

    connect(ui->backSpace, SIGNAL(clicked()),
            this, SLOT(deletePreviousSymbol()));

    connect(ui->clear, &QPushButton::clicked,
            ui->expression, &QTextBrowser::clear);

    connect(ui->getResult, SIGNAL(clicked()),
            this, SLOT(calculate()));
}


void MainWindow::printExpression(const QString &text)
{
    ui->expression->insertPlainText(text);
}


void MainWindow::deletePreviousSymbol()
{
    ui->expression->textCursor().deletePreviousChar();
}


void MainWindow::calculate()
{
    try
    {
        ui->expression->;
    }
}


MainWindow::~MainWindow()
{
    delete forPrinting;
    delete ui;
}
