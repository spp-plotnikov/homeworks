#include <QSignalMapper>
#include <ctype.h>
#include <cmath>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../../../2sem/hw1/task1_2/calculator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");

    foreach (QPushButton *button, this->findChildren<QPushButton*>())
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
    char symbol = text.toLocal8Bit().constData()[0];

    if (text != QString(",") && text != QString(")") && !isdigit(symbol))
        ui->expression->insertPlainText(QString(" "));
    ui->expression->insertPlainText(text);
    if (text != QString(",") && text != QString("(") && !isdigit(symbol))
        ui->expression->insertPlainText(QString(" "));
}


void MainWindow::deletePreviousSymbol()
{
    ui->expression->textCursor().deletePreviousChar();
}


void MainWindow::calculate()
{
    Calculator *calculator = new Calculator;
    char forCalculating[1024] = {};
    strcpy(forCalculating, ui->expression->toPlainText().toLocal8Bit().constData());
    double result = 0.0;

    result = calculator->calculate(forCalculating);

    if (!std::isinf(result) && !std::isnan(result))
    {
        ui->result->setText(QString::number(result));
    }
    else
    {
        ui->result->setText(QString("incorrect input"));
    }

    delete calculator;
}


MainWindow::~MainWindow()
{
    delete forPrinting;
    delete ui;
}
