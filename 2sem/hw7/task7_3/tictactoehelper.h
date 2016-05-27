#pragma once

#include <QPushButton>


/*!
 * \brief This is the helper class to using only for TicTacToe class (S P P Tic Tac Toe game)
 */
class TicTacToeHelper
{
public:
    /*!
     * \brief checks for win and marks disabled chain of winner's buttons
     * \param field is field of buttons with crosses and zeros
     * \param sizeOfField is the size of field (really??)
     * \param x is position of button in string
     * \param y is position of button in column
     * \return true if this button (x, y) is in the winner's chain of buttons
     * \attention (!!!) the buttons that are in the chain of the winner will be marked as disabled
     */
    static bool isVictory(QPushButton ***field, const int &sizeOfField, int x, int y);

private:
    static bool checkLineForChain(QPushButton ***field, const int &sizeOfField, int x, int y, int shiftX, int shiftY);
};
