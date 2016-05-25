#pragma once

#include<QSignalMapper>
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
    /// \brief increases field by 1 (increment)
    void increaseField();
    /// \brief decreases field by 1 (decrement)
    void decreaseField();

private:
    /// \brief creates a field of size n x n
    void generateField(const int &size);
    void deleteField();

    Ui::TicTacToe *ui;

    int sizeOfField = 3;    ///<    starting value
    QPushButton ***field = nullptr;
    QSignalMapper *signalMapper = nullptr;
};
