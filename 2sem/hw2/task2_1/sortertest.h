#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <ctime>
#include "bubblesorter.h"
#include "quicksorter.h"
#include "heapsorter.h"
#include "sorter.h"

class SorterTest : public QObject
{
    Q_OBJECT
public:
    explicit SorterTest(QObject *parent = 0) : QObject(parent) {}


private slots:
    void init()
    {
        bubbleSorter = new BubbleSorter();
        quickSorter = new QuickSorter();
        heapSorter = new HeapSorter();
    }

    void oneElementTest_data()
    {
        QTest::addColumn<int>("type");

        QTest::newRow("bubble") << 0;
        QTest::newRow("quick") << 1;
        QTest::newRow("heap") << 2;
    }

    void oneElementTest()
    {
        QFETCH(int, type);
        setCurrentType(type);

        int array[1] = {1};
        sorter->sort(array, 1);

        QVERIFY(array[0] == 1);
    }

    void sortedByAscendingArrayTest_data()
    {
        QTest::addColumn<int>("type");

        QTest::newRow("bubble") << 0;
        QTest::newRow("quick") << 1;
        QTest::newRow("heap") << 2;
    }

    void sortedByAscendingArrayTest()
    {
        QFETCH(int, type);
        setCurrentType(type);

        int array[100] = {};
        for (int i = 0; i < 100; i++)
        {
            array[i] = i;
        }
        sorter->sort(array, 100);
        QVERIFY(isSorted(array, 100));
    }

    void sortedInDescendingOrderTest_data()
    {
        QTest::addColumn<int>("type");

        QTest::newRow("bubble") << 0;
        QTest::newRow("quick") << 1;
        QTest::newRow("heap") << 2;
    }

    void sortedInDescendingOrderTest()
    {
        QFETCH(int, type);
        setCurrentType(type);

        int array[100] = {};
        for (int i = 0; i < 100; i++)
        {
            array[i] = 100 - i;
        }
        sorter->sort(array, 100);
        QVERIFY(isSorted(array, 100));
    }

    void randomArrayTest_data()
    {
        QTest::addColumn<int>("type");

        QTest::newRow("bubble") << 0;
        QTest::newRow("quick") << 1;
        QTest::newRow("heap") << 2;
    }

    void randomArrayTest()
    {
        QFETCH(int, type);
        setCurrentType(type);

        srand(time(NULL));
        const int size = 200 + rand() % 10000;
        int *array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = rand() % 4001 - 2000;
        }

        sorter->sort(array, size);
        bool result = isSorted(array, size);
        delete array;
        QVERIFY(result);
    }

    void cleanup()
    {
        delete bubbleSorter;
        delete quickSorter;
        delete heapSorter;
    }

private:
    void setCurrentType(int type)
    {
        switch (type) {
        case bubble:
            sorter = bubbleSorter;
            break;
        case quick:
            sorter = quickSorter;
            break;
        case heap:
            sorter = heapSorter;
            break;
        }
    }

    bool isSorted(int *array, int length)
    {
        bool isCorrectOrder = true;
        for (int i = 0; i < length - 1; i++)
        {
            isCorrectOrder &= array[i] <= array[i + 1];
        }
        return isCorrectOrder;
    }

    enum Types {bubble, quick, heap};

    Sorter *bubbleSorter = NULL;
    Sorter *quickSorter = NULL;
    Sorter *heapSorter = NULL;
    Sorter *sorter = NULL;
};
