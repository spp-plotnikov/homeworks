#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "priorityqueue.h"

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
        queue->enqueue(7, 0);
        QVERIFY(!queue->isEmpty());
    }


    void removeTest()
    {
        queue->dequeue();
        QVERIFY(queue->isEmpty());
    }
private:
    PriorityQueue<int> *queue;
};
