#include <QCoreApplication>
#include <iostream>
#include <ctime>
#include "printer.h"
#include "printertest.h"
#include "fileprinter.h"
#include "consoleprinter.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PrinterTest test;
    QTest::qExec(&test);

    cout << "This app displays the numbers from the array of size NxN ";
    cout << "in a spiral starting from the centre. N must be odd." << endl;
    cout << "Please enter N" << endl;

    int size = 0;
    cin >> size;

    int **arrayOfDigits;
    arrayOfDigits = new int*[size];
    for (int i = 0; i < size; i++)
    {
        arrayOfDigits[i] = new int[size];
    }

    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arrayOfDigits[i][j] = (rand() % 10);
        }
    }

    cout << "Print the program's result to the console or to a file?" << endl;
    cout << "0 - console; 1 - file" << endl;

    enum placesPrint {console, file};
    int placePrint = 0;
    cin >> placePrint;
    Printer *printer = NULL;
    if (placePrint == file)
    {
        cout << "Please enter the name of your file for output data." << endl;
        const int maxNameLength = 256;
        char theOutputFileName[maxNameLength] = {};
        cin >> theOutputFileName;
        printer = new FilePrinter(theOutputFileName);
    }
    else if (placePrint == console)
    {
        printer = new ConsolePrinter();
    }
    else
    {
        cout << "Error: It must only be 0 or 1!" << endl;
    }

    printer->print(arrayOfDigits, size);

    delete printer;
    for (int i = 0; i < size; i++)
    {
        delete []arrayOfDigits[i];
    }
    delete []arrayOfDigits;
    return a.exec();
}
