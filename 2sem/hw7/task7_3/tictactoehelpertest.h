#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <QPushButton>
#include "tictactoehelper.h"


class TicTacToeHelperTest : public QObject
{
   Q_OBJECT
public:
   explicit TicTacToeHelperTest(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
       generateField(3);
   }

   void cleanup()
   {
       deleteField(3);
   }

   void firstStringTest()
   {
       for (int i = 0; i < 3; i++)
       {
           field[0][i]->setToolTip("O");
       }
       QVERIFY(TicTacToeHelper::isVictory(field, 3, 0, 2));
   }

   void thirdStringTest()
   {
       for (int i = 0; i < 3; i++)
       {
           field[2][i]->setToolTip("O");
       }
       QVERIFY(TicTacToeHelper::isVictory(field, 3, 2, 1));
   }

   void secondColumnTest()
   {
       for (int i = 0; i < 3; i++)
       {
           field[i][1]->setToolTip("O");
       }
       QVERIFY(TicTacToeHelper::isVictory(field, 3, 2, 1));
   }

   void mainDiagonalTest()
   {
       for (int i = 0; i < 3; i++)
       {
           field[i][i]->setToolTip("X");
       }
       QVERIFY(TicTacToeHelper::isVictory(field, 3, 0, 0));
   }

   void antidiagonalTest()
   {
       for (int i = 0; i < 3; i++)
       {
           field[i][2 - i]->setToolTip("O");
       }
       QVERIFY(TicTacToeHelper::isVictory(field, 3, 1, 1));
   }

   void matrix5x5test()
   {
       deleteField(3);
       generateField(5);

       for (int i = 1; i < 4; i++)
       {
           field[i][1]->setToolTip("X");
       }
       QVERIFY(TicTacToeHelper::isVictory(field, 5, 3, 1));
       deleteField(5);
   }

   void matrix8x8test()
   {
       deleteField(3);
       generateField(8);

       for (int i = 0; i < 3; i++)
       {
           field[i + 4][6 - i]->setToolTip("O");
       }
       QVERIFY(TicTacToeHelper::isVictory(field, 8, 6, 4));
       deleteField(8);
   }

   void isNotVictory()
   {
       field[0][0]->setToolTip("X");
       field[0][1]->setToolTip("O");
       field[0][2]->setToolTip("X");
       QVERIFY(!TicTacToeHelper::isVictory(field, 3, 0, 0));
   }

private:
   void generateField(int size)
   {
       field = new QPushButton**[size];
       for (int i = 0; i < size; i++)
       {
           field[i] = new QPushButton*[size];
           for (int j = 0; j < size; j++)
           {
               field[i][j] = new QPushButton();
           }
       }
   }

   void deleteField(int size)
   {
       if (!field)
           return;

       for (int i = 0; i < size; i++)
       {
           for (int j = 0; j < size; j++)
           {
               delete field[i][j];
           }
           delete []field[i];
       }
       delete []field;
       field = nullptr;
   }

   QPushButton ***field = nullptr;
};
