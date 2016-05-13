#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "stack.h"
#include "arraystack.h"
#include "pointerstack.h"

class StackTest : public QObject
{
   Q_OBJECT
public:
   explicit StackTest(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
       arrayStack = new ArrayStack<int>();
       pointerStack = new PointerStack<int>();
   }

   void cleanup()
   {
       delete arrayStack;
       delete pointerStack;
   }

   void pushTest_data()
   {
       QTest::addColumn<int>("type");

       QTest::newRow("array") << 0;
       QTest::newRow("pointer") << 1;

   }

   void pushTest()
   {
       QFETCH(int, type);
       setType(type);

       currentStack->push(42);
       QVERIFY(currentStack->viewTheTop() == 42);
   }

   void popTest_data()
   {
       QTest::addColumn<int>("type");

       QTest::newRow("array") << 0;
       QTest::newRow("pointer") << 1;
   }

   void popTest()
   {
       QFETCH(int, type);
       setType(type);

       currentStack->push(666);

       QVERIFY(currentStack->pop() == 666);
   }

   void manyElementsTest_data()
   {
       QTest::addColumn<int>("type");

       QTest::newRow("array") << 0;
       QTest::newRow("pointer") << 1;
   }

   void manyElementsTest()
   {
       QFETCH(int, type);
       setType(type);

       for (int i = 42; i <= 100500; i++)
       {
           currentStack->push(i);
       }

       bool isRight = true;
       for (int i = 100500; i >= 42; i--)
       {
           isRight &= currentStack->pop() == i;
       }
       QVERIFY(isRight);
   }

private:
   void setType(int type)
   {
       if (type)
           currentStack = arrayStack;
       else
           currentStack = pointerStack;
   }

   Stack<int> *arrayStack = nullptr;
   Stack<int> *pointerStack = nullptr;
   Stack<int> *currentStack = nullptr;

};
