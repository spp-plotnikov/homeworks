#include <iostream>
#include <QCoreApplication>
#include "arithmetictree.h"
#include "arithmetictreetest.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ArithmeticTreeTest test;
    QTest::qExec(&test);

    cout << "This program calculates the value of the expression represented as a tree" << endl;
    cout << "Please be careful not to DIVIDE BY ZERO!" << endl;
    cout << "Please enter the name of input file" << endl;

    const int maxNameLength = 256;
    char theFileName[maxNameLength] = {};
    cin >> theFileName;

    FILE *userInputFile = fopen(theFileName, "r");
    if (userInputFile == nullptr)
    {
        cout << "Error: Cannot open file!" << endl;
        return 0;
    }

    ArithmeticTree *tree = new ArithmeticTree(userInputFile);

    cout << "Print the program's result to the console or to a file?" << endl;
    cout << "0 - console; 1 - file" << endl;

    int placePrint = 0;
    cin >> placePrint;
    enum PlacesOfPrint {console, file};
    if (placePrint == file)
    {
        cout << "Please enter the name of your file for output data." << endl;
        cin >> theFileName;

        FILE *userOutputFile = freopen(theFileName, "w", stdout);
        cout << "Result: " << tree->calculateTree() << endl;
        tree->printTree(cout);
        fclose(userOutputFile);
    }
    else if (placePrint == console)
    {
        cout << "Result: " << tree->calculateTree() << endl;
        tree->printTree(cout);
    }
    else
    {
        cout << "Error: It must only be 1 or 2!" << endl;
    }

    delete tree;
    fclose(userInputFile);
    cout << endl;

    return a.exec();
}
