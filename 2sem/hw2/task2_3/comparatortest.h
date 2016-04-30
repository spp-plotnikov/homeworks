#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "pointerlist.h"
#include "comparator.h"
#include "list.h"


class ComparatorTest : public QObject
{
    Q_OBJECT
public:
    explicit ComparatorTest(QObject *parent = 0) : QObject(parent) {}


private slots:
    void init()
    {
        first = new PointerList();
        second = new PointerList();
        for (int i = 0; i < 42; i++)
        {
            first->add(i);
            second->add(i);
        }
    }

    void firstIsBigger()
    {
        for (int i = 0; i < 20; i++)
        {
            first->add(i);
        }
        QCOMPARE(Comparator<List>::compare(first, second), 1);
    }

    void secondIsBigger()
    {
        for (int i = 0; i < 13; i++)
        {
            second->add(i);
        }
        QCOMPARE(Comparator<List>::compare(first, second), -1);
    }

    void areEqual()
    {
        QCOMPARE(Comparator<List>::compare(first, second), 0);
    }

    void cleanup()
    {
        delete first;
        delete second;
    }

private:
    List *first = nullptr;
    List *second = nullptr;
};
