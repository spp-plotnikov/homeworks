#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "pointerlist.h"
#include "sortedset.h"
#include "list.h"


class SortedSetTest : public QObject
{
    Q_OBJECT
public:
    explicit SortedSetTest(QObject *parent = 0) : QObject(parent) {}


private slots:
    void init()
    {
        set = new SortedSet<List>();
        list1 = new PointerList();
        list2 = new PointerList();

        for (int i = 0; i < 42; i++)
        {
            list1->add(i);
            list2->add(42 - i);
        }
    }

    void addTest()
    {
        set->add(list1);
        QVERIFY(set->isFound(list2));
        //  We can use list2 in this case because list1 and list2 are equal by len
        //  We don't use list1 because the test will pass even in the presence of a bug.
        //  For example, you can compare the list by pointer and
        //  not by the length of the list.
        //  That is why we create a new list with the same length
    }

    void removeTest()
    {
        set->add(list1);
        set->remove(list2);
        QVERIFY(!set->isFound(list1));
    }

    void exceptionTest()
    {
        bool exception = false;

        set->add(list1);
        try
        {
            set->add(list2);
        }
        catch (SortedSet<List>::ElementExistsException &)
        {
            exception = true;
        }

        QVERIFY(exception);
    }

    void cleanup()
    {
        delete set;
        delete list1;
        delete list2;
    }

private:
    List *list1 = nullptr;
    List *list2 = nullptr;
    SortedSet<List> *set = nullptr;
};
