#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "priorityqueue.h"
#include "deletingfromemptyqueue.h"

class PriorityQueueTest : public QObject
{
    Q_OBJECT
public:
    explicit PriorityQueueTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        queue = new PriorityQueue<int>();
    }


    void cleanup()
    {
        delete queue;
    }


    void isEmptyTest()
    {
        QVERIFY(queue->isEmpty());
    }


    void exceptionTest()
    {
        bool exception = false;

        try
        {
            queue->dequeue();
        }
        catch (DeletingFromEmptyQueue &)
        {
            exception = true;
        }

        QVERIFY(exception);
    }


    void addTest()
    {
        queue->enqueue(7, 1);
        QVERIFY(!queue->isEmpty());
    }


    void removeTest()
    {
        queue->enqueue(42, 1); // 42 is the answer to The Ultimate Question of Life, the Universe, and Everything
        queue->dequeue();
        QVERIFY(queue->isEmpty());
    }


    void priorityTest()
    {
        queue->enqueue(0, 1);
        queue->enqueue(3, 3);
        queue->enqueue(1, 2);
        queue->enqueue(2, 2);
        queue->enqueue(4, 3);

        bool result = true;
        for (int i = 0; i < 5; i++)
        {
            result &= (queue->dequeue() == i);
        }
        QVERIFY(result);
    }


    void veryMuchElementsTest()
    {
        for (int i = 0; i < 10000; i++)
        {
            queue->enqueue(i, i % 10);
        }
        for (int i = 0; i < 10000; i++)
        {
            queue->dequeue();
        }
        QVERIFY(queue->isEmpty());
    }

private:
    PriorityQueue<int> *queue;
};


QTEST_MAIN(PriorityQueueTest)
