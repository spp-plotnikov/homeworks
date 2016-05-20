#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "comparator.h"
#include "intsinabsolutevaluecomparator.h"


class ComparatorTest : public QObject
{
    Q_OBJECT
public:
    explicit ComparatorTest(QObject *parent = 0) : QObject(parent) {}


private slots:
    void init()
    {
        comparator = new IntsInAbsoluteValueComparator<int>();
    }

    void firstIsBigger()
    {
        QCOMPARE(comparator->compare(-7, 4), 1);
    }

    void secondIsBigger()
    {
        QCOMPARE(comparator->compare(36, 42), -1);
    }

    void areEqual()
    {
        QCOMPARE(comparator->compare(7, -7), 0);
    }

    void cleanup()
    {
        delete comparator;
    }

private:
    Comparator<int> *comparator = nullptr;
};
