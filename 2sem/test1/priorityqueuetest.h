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
private:
    PriorityQueue<int> *queue;
};


QTEST_MAIN(PriorityQueueTest)
