#pragma once

#include <QSignalMapper>
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
    /// \brief sets the button icon and checks for the win
    void markCell(const int &position);
    /// \brief starts the game again
    void replay();

private:
    /// \brief creates a field of size n x n
    void generateField(const int &size);
    void deleteField();
    void checkForWin(int x, int y);
    void announceTheVictory();
    void changePlayer();

    Ui::TicTacToe *ui;

    int sizeOfField = 3;    ///<    starting value
    bool whoseTurn = true;  ///<    true if the move of the 1st player, false if the move of the 2nd
    QPushButton ***field = nullptr;
    QSignalMapper *signalMapper = nullptr;
};
