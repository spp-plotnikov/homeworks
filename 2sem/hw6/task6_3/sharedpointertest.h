#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "sharedpointer.h"


class SharedPointerTest : public QObject
{
    Q_OBJECT
public:
    explicit SharedPointerTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void oneCopyCountTest()
    {
        SharedPointer<int> pointer(new int(7));
        QCOMPARE(pointer.getCount(), 1);
    }

    void correctPointerDereferenceTest()
    {
        SharedPointer<int> pointer(new int(42));
        QCOMPARE(*pointer, 42);
    }

    void twoCopiesTest()
    {
        SharedPointer<int> pointerCopy1(new int(666));
        SharedPointer<int> pointerCopy2(pointerCopy1);
        QCOMPARE(pointerCopy1.getCount(), 2);
    }

    void removeCopyTest()
    {
        SharedPointer<int> pointerCopy1(new int(777));
        SharedPointer<int> pointerCopy2(pointerCopy1);

        pointerCopy2.~SharedPointer();
        QCOMPARE(pointerCopy1.getCount(), 1);
    }

    void correctCopyDereferenceTest()
    {
        SharedPointer<int> pointerCopy1(new int(3));
        SharedPointer<int> pointerCopy2(pointerCopy1);

        QCOMPARE(*pointerCopy2, 3);
    }

    void arrowAccessOperatorTest()
    {
        SharedPointer<ReturnerOfSeven> pointer(new ReturnerOfSeven);

        QCOMPARE(pointer->returnSeven(), 7);
    }

    void exceptionTest()
    {
        SharedPointer<int> nullPoinrer(nullptr);
        QVERIFY_EXCEPTION_THROWN(*nullPoinrer, SharedPointer<int>::NullPointerException);
    }

    void assignmentOperatorTest()
    {
        SharedPointer<int> pointer1(new int(33));
        SharedPointer<int> pointer2(new int(44));
        pointer2 = pointer1;
        QCOMPARE(*pointer2, 33);
        QCOMPARE(pointer1.getCount(), 2);
    }

    void nullPointerCountTest()
    {
        SharedPointer<int> nullPointer(nullptr);

        QCOMPARE(nullPointer.getCount(), 0);
    }

private:
    class ReturnerOfSeven
    {
    public:
        int returnSeven()
        {
            return 7;
        }
    };
};

