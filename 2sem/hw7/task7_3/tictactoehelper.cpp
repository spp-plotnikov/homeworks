#include "tictactoehelper.h"

bool TicTacToeHelper::isVictory(QPushButton ***field, const int &sizeOfField, int x, int y)
{
    if (checkLineForChain(field, sizeOfField, x, y, 1, 1))
        return true;
    if (checkLineForChain(field, sizeOfField, x, y, 1, -1))
        return true;
    if (checkLineForChain(field, sizeOfField, x, y, 1, 0))
        return true;
    if (checkLineForChain(field, sizeOfField, x, y, 0, 1))
        return true;
    return false;
}


//-------------------------------------------------------


bool TicTacToeHelper::checkLineForChain(QPushButton ***field, const int &sizeOfField, int x, int y, int shiftX, int shiftY)
{
    while (x >= 0 && x < sizeOfField && y >= 0 && y < sizeOfField)
    {
        x -= shiftX;
        y -= shiftY;
    }

    int count = 0;
    x += shiftX;
    y += shiftY;
    do
    {
        x += shiftX;
        y += shiftY;
        if (x < 0 || x > sizeOfField - 1 || y < 0 || y > sizeOfField - 1)
            break;
        if (field[x - shiftX][y - shiftY]->toolTip() == field[x][y]->toolTip() && !field[x][y]->toolTip().isEmpty())
        {
            count++;
        }
        else
        {
            count = 0;
        }

        if (count == 2)
        {
            field[x - 2 * shiftX][y - 2 * shiftY]->setEnabled(false);
            field[x - shiftX][y - shiftY]->setEnabled(false);
            field[x][y]->setEnabled(false);
            return true;
        }
    } while (x >= 0 && x < sizeOfField && y >= 0 && y < sizeOfField);
    return false;
}
