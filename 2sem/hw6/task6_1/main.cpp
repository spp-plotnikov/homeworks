#include <QCoreApplication>
#include <iostream>
#include "veryusefulclass.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "This application demonstrates that all of the destructors ";
    cout << "of objects created in a block are called before ";
    cout << "this block will generate an exception." << endl;

    try
    {
        VeryUsefulClassChild object;
        object.toDivideByZero();
    }
    catch (VeryUsefulClassChild::DivideByZeroException &)
    {
        cout << "Exception was thrown" << endl;
    }

    return a.exec();
}
