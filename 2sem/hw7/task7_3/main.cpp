#include "tictactoe.h"
#include "tictactoehelpertest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TicTacToeHelperTest test;
    QTest::qExec(&test);

    TicTacToe w;
    w.show();

    return a.exec();
}
