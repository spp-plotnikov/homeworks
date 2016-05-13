#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <fstream>
#include <cstdio>
#include "printer.h"
#include "fileprinter.h"


class PrinterTest : public QObject
{
   Q_OBJECT
public:
   explicit PrinterTest(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
        printer = new FilePrinter("temp.spp");    //  ConsolePrinter needs no testing because it is equivalent.
   }

   void cleanup()
   {
        delete printer;
        remove("temp.spp");
   }

   void oneElementTest()
   {
        newArray(1);
        array[0][0] = 7;
        printer->print(array, 1);
        deleteArray(1);

        getString(1);
        QVERIFY(strcmp(string, "7 ") == 0);
   }

   void matrix3x3Test()
   {
       newArray(3);
       for (int i = 0; i < 3; i++)
           for (int j = 0; j < 3; j++)
               array[i][j] = i;
       printer->print(array, 3);
       deleteArray(3);

       getString(3);
       QVERIFY(strcmp(string, "1 0 0 1 2 2 2 1 0 ") == 0);
   }

   void matrix7x7Test()
   {
       newArray(7);
       for (int i = 0; i < 7; i++)
           for (int j = 0; j < 7; j++)
               array[i][j] = (i + j) % 2;
       printer->print(array, 7);
       deleteArray(7);

       getString(7);
       bool isCorrect = true;
       for (int i = 1; i < 49; i++)
       {
           if (i % 2)
               isCorrect &= string[2 * i] == '1';
           else
               isCorrect &= string[2 * i] == '0';
       }
       QVERIFY(isCorrect);
   }

private:
    void getString(const int size)
    {
        ifstream in ("temp.spp");
        for (int i = 0; i < size + 2; i++)  //  skip extra strings
        {
            in.getline(string, 2048);
        }
        in.getline(string, 2048);
        in.close();
    }

    void newArray(const int size)
    {
        array = new int*[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = new int[size];
        }
    }

    void deleteArray(const int size)
    {
        for (int i = 0; i < size; i++)
        {
            delete []array[i];
        }
        delete []array;
    }

    Printer *printer = NULL;
    char string[2048] = {};
    int **array = NULL;
};
