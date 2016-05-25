#include "tictactoe.h"
#include "ui_tictactoe.h"

TicTacToe::TicTacToe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TicTacToe)
{
    ui->setupUi(this);
    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");
    ui->player1icon->setPixmap(QPixmap(":new/prefix1/images/player1.png"));
    ui->player2icon->setPixmap(QPixmap(":new/prefix1/images/player2.png"));
    ui->decreaseField->setIcon(QIcon(":new/prefix1/images/minus.png"));
    ui->increaseField->setIcon(QIcon(":new/prefix1/images/plus.png"));
    generateField(sizeOfField);
}

TicTacToe::~TicTacToe()
{
    delete ui;
}


//-------------------------------------------------------


void TicTacToe::generateField(const int &size)
{
    if (size < 3 || size > 9)
        return;

//    deleteField();
    field = new QPushButton**[size];
    const int sizeOfButton = 73 - 5 * (size - 3);
    for (int i = 0; i < size; i++)
    {
        field[i] = new QPushButton*[size];
        for (int j = 0; j < size; j++)
        {
            field[i][j] = new QPushButton();
            field[i][j]->setFixedSize(sizeOfButton, sizeOfButton);
            ui->fieldLayout->addWidget(field[i][j], i, j);
        }
    }
    //setFixedSize(sizeHint());
}
