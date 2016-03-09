#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");
    connect(ui->operand1, SIGNAL(valueChanged(int)),
                this, SLOT(recalculate()));
    connect(ui->operand2, SIGNAL(valueChanged(int)),
                this, SLOT(recalculate()));
    connect(ui->operation, SIGNAL(currentIndexChanged(int)),
                this, SLOT(recalculate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::recalculate()
{
    int firstOperand = ui->operand1->value();
    int secondOperand = ui->operand2->value();
    int operation = ui->operation->currentIndex();
    double result = 0;

    enum {plus, minus, multiplication, division};
    switch (operation)
    {
    case plus:
        result = firstOperand + secondOperand;
        break;
    case minus:
        result = firstOperand - secondOperand;
        break;
    case multiplication:
        result = firstOperand * secondOperand;
        break;
    case division:
        if (secondOperand != 0)
        {
           result = static_cast < double > ( firstOperand ) / secondOperand;
        }
        else
        {
            ui->result->setText("Error: division by zero!");
            return;
        }
        break;
    }
    ui->result->setText(QString::number(result, 'g', 6));
}
