#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <ctime>
#include "intsinabsolutevaluecomparator.h"
#include "bubblesorter.h"
#include "comparator.h"

class SorterTest : public QObject
{
    Q_OBJECT
public:
    explicit SorterTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void emptyListTest()
    {
        QList<int> list;
        BubbleSorter<int>::sort(list, IntsInAbsoluteValueComparator<int>());
        QVERIFY(list.isEmpty());
    }

    void oneElementTest()
    {
        QList<int> list;
        list.append(42);
        BubbleSorter<int>::sort(list, IntsInAbsoluteValueComparator<int>());
        QCOMPARE(list[0], 42);
        QCOMPARE(list.size(), 1);
    }

    void randTest()
    {
        srand(time(0));

        QList<int> list;
        for (int i = 0; i < 100 + rand() % 7000; i++)
        {
            list.append(rand() % 2000 - 1000);
        }

        IntsInAbsoluteValueComparator<int> comparator;
        BubbleSorter<int>::sort(list, comparator);

        bool isRightOrder = true;
        for (int i = 0; i < list.size() - 1; i++)
        {
            isRightOrder &= comparator.compare(list[i], list[i + 1]) != 1;
        }

        QVERIFY(isRightOrder);
    }
};
