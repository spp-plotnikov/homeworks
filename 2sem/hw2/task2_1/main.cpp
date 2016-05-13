#include <QCoreApplication>
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <iostream>
#include <ctime>
#include "bubblesorter.h"
#include "quicksorter.h"
#include "heapsorter.h"
#include "sortertest.h"
#include "sorter.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(NULL));

    SorterTest test;
    QTest::qExec(&test);

    cout << "This app is sorter" << endl;
    cout << "Please enter the size of the array of random variables" << endl;
    int size = 0;
    cin >> size;

    int *array = new int[size];
    for (int i = 0; i < size; i++)
            array[i] = rand() % 100;

    cout << "Please select the type of sorting:" << endl;
    cout << "0 - bubble sort: The best sorting ever :-)" << endl;
    cout << "1 - quick sort" << endl;
    cout << "2 - heap sort" << endl;
    int type = 0;
    cin >> type;

    Sorter *sorter = NULL;
    enum Types {bubble, quick, heap};
    switch (type) {
    case bubble:
        sorter = new BubbleSorter();
        break;
    case quick:
        sorter = new QuickSorter();
        break;
    case heap:
        sorter = new HeapSorter();
        break;
    default:
    {
        cout << "Error: unknown type of sorting!" << endl;
        return a.exec();
    }
    }

    cout << endl << "Before sorting: " << endl;
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    sorter->sort(array, size);
    cout << endl << "After sorting: " << endl;
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;

    delete []array;
    delete sorter;
    return a.exec();
}
