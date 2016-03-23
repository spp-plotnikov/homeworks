#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>
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
    void  init1_data()
    {
        QTest::addColumn<int>("type");

        QTest::newRow("bubble") << 0;
        QTest::newRow("quick") << 1;
        QTest::newRow("heap") << 2;
    }

    void init1()
    {
        QFETCH(int, type);

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
        }
    }

    void oneElementTest()
    {
        int a[10] = {};
        a[0] = 1;
        sorter->sort(a, 1);
    }

    void cleanup()
    {
        delete sorter;
    }



private:
    Sorter *sorter;
};
