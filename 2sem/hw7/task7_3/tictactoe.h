#pragma once

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class TicTacToe;
}

class TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    explicit TicTacToe(QWidget *parent = 0);
    ~TicTacToe();

private slots:
    /// \brief creates a field of size n x n
    void generateField(const int &size);

private:
    Ui::TicTacToe *ui;

    int sizeOfField = 3;    ///<    starting value
    QPushButton ***field = nullptr;
};
