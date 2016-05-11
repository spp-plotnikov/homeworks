#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "uniquelist.h"
#include "../../../2sem/hw1/task1_1/list.h"
#include "../../../2sem/hw1/task1_1/arraylist.h"
#include "../../../2sem/hw1/task1_1/pointerlist.h"

class UniqueListTest : public QObject
{
    Q_OBJECT
public:
    explicit UniqueListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        arrayUniqueList = new ArrayUniqueList();
        pointerUniqueList = new PointerUniqueList();
    }

    void cleanup()
    {
        delete arrayUniqueList;
        delete pointerUniqueList;
    }

    void addTest_data()
    {
        QTest::addColumn<int>("type");

        QTest::newRow("array") << 0;
        QTest::newRow("pointer") << 1;
    }

    void addTest()
    {
        QFETCH(int, type);
        setType(type);

        currentList->add(777);
        QVERIFY(currentList->isFound(777));
    }

    void removeTest_data()
    {
        QTest::addColumn<int>("type");

        QTest::newRow("array") << 0;
        QTest::newRow("pointer") << 1;
    }

    void removeTest()
    {
        QFETCH(int, type);
        setType(type);

        currentList->add(100500);

        currentList->remove(100500);

        QVERIFY(!currentList->isFound(100500));
    }

    void addExceptionTest_data()
    {
        QTest::addColumn<int>("type");

        QTest::newRow("array") << 0;
        QTest::newRow("pointer") << 1;
    }

    void addExceptionTest()
    {
        QFETCH(int, type);
        setType(type);

        bool exception = false;
        try
        {
            currentList->add(42);
            currentList->add(42);
        }
        catch (UniqueList::ElementAlreadyExistsException &)
        {
            exception = true;
        }
        QVERIFY(exception);
    }

    void removeExceptionTest_data()
    {
        QTest::addColumn<int>("type");

        QTest::newRow("array") << 0;
        QTest::newRow("pointer") << 1;
    }

    void removeExceptionTest()
    {
        QFETCH(int, type);
        setType(type);

        bool exception = false;
        try
        {
            currentList->remove(42);
        }
        catch (UniqueList::AttemptToRemoveTheNonExistentElementException &)
        {
            exception = true;
        }
        QVERIFY(exception);
    }

private:
    void setType(int type)
    {
        if (type)
            currentList = arrayUniqueList;
        else
            currentList = pointerUniqueList;
    }

    UniqueList *arrayUniqueList = nullptr;
    UniqueList *pointerUniqueList = nullptr;
    List *currentList = nullptr;
};


QTEST_MAIN(UniqueListTest)
