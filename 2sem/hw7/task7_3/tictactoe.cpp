#include "tictactoe.h"
#include "ui_tictactoe.h"
#include "tictactoehelper.h"

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
    ui->restart->setIcon(QIcon(":new/prefix1/images/restart1.png"));
    ui->exit->setIcon(QIcon(":new/prefix1/images/exit1.png"));
    generateField(sizeOfField);

    connect(ui->increaseField, SIGNAL(clicked()), this, SLOT(increaseField()));
    connect(ui->decreaseField, SIGNAL(clicked()), this, SLOT(decreaseField()));
    connect(ui->exit, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->restart, SIGNAL(clicked()), this, SLOT(replay()));
}

TicTacToe::~TicTacToe()
{
    deleteField();
    delete ui;
}


//-------------------------------------------------------


void TicTacToe::increaseField()
{
    generateField(sizeOfField + 1);
}


void TicTacToe::decreaseField()
{
    generateField(sizeOfField - 1);
}


void TicTacToe::markCell(const int &position)
{
    const int x = position / 10;
    const int y = position % 10;
    if (!field[x][y]->icon().isNull())
        return;

    if (whoseTurn)
    {
        field[x][y]->setIcon(QIcon(":new/prefix1/images/x1.png"));
        field[x][y]->setToolTip("X");
    }
    else
    {
        field[x][y]->setIcon(QIcon(":new/prefix1/images/o1.png"));
        field[x][y]->setToolTip("O");
    }
    changePlayer();
    checkForWin(x, y);
}


void TicTacToe::replay()
{
    generateField(sizeOfField);
}


//-------------------------------------------------------


void TicTacToe::generateField(const int &size)
{
    if (size < 3 || size > 9)
        return;

    ui->player1label->setText("Player 1");
    ui->player2label->setText("Player 2");
    ui->exit->setVisible(false);
    ui->restart->setVisible(false);

    deleteField();
    sizeOfField = size;
    field = new QPushButton**[size];
    signalMapper = new QSignalMapper();
    const int sizeOfButton = 73 - 5 * (size - 3);
    for (int i = 0; i < size; i++)
    {
        field[i] = new QPushButton*[size];
        for (int j = 0; j < size; j++)
        {
            field[i][j] = new QPushButton();
            field[i][j]->setFixedSize(sizeOfButton, sizeOfButton);
            field[i][j]->setIconSize(QSize(sizeOfButton - 6, sizeOfButton - 6));
            ui->fieldLayout->addWidget(field[i][j], i, j);
            signalMapper->setMapping(field[i][j], i * 10 + j);
            connect(field[i][j], SIGNAL(clicked()), signalMapper, SLOT(map()));
        }
    }
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(markCell(int)));
}


void TicTacToe::deleteField()
{
    if (!field)
        return;

    for (int i = 0; i < sizeOfField; i++)
    {
        for (int j = 0; j < sizeOfField; j++)
        {
            delete field[i][j];
        }
        delete []field[i];
    }
    delete []field;
    delete signalMapper;
}


void TicTacToe::checkForWin(int x, int y)
{
    if (TicTacToeHelper::isVictory(field, sizeOfField, x, y))
    {
        announceTheVictory();
    }
}


void TicTacToe::announceTheVictory()
{
    for (int i = 0; i < sizeOfField; i++)
    {
        for (int j = 0; j < sizeOfField; j++)
        {
            field[i][j]->setEnabled(!field[i][j]->isEnabled());
        }
    }

    changePlayer();
    if (whoseTurn)
    {
        ui->player1label->setText("Winner!");
    }
    else
    {
        ui->player2label->setText("Winner!");
    }
    ui->exit->setVisible(true);
    ui->restart->setVisible(true);
}


void TicTacToe::changePlayer()
{
    ui->player1icon->setEnabled(!whoseTurn);
    ui->player1label->setEnabled(!whoseTurn);
    ui->player2icon->setEnabled(whoseTurn);
    ui->player2label->setEnabled(whoseTurn);
    whoseTurn = !whoseTurn;
}
