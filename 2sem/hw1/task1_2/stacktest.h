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
       QTest::addColumn<int>("number");

       QTest::newRow("largeNegativeNumber") << -100500;
       QTest::newRow("negativeNumber") << -777;
       QTest::newRow("zero") << 0;
       QTest::newRow("answerToTheUltimateQuestion") << 42;
       QTest::newRow("positiveNumber") << 666;
       QTest::newRow("largePositiveNumber") << 1000000000;
   }

   void pushTest()
   {
       QFETCH(int, number);

       arrayStack->push(number);
       pointerStack->push(number);
       QVERIFY(arrayStack->viewTheTop() == number && pointerStack->viewTheTop() == number);
   }

   void popTest_data()
   {
       QTest::addColumn<int>("number");

       QTest::newRow("largeNegativeNumber") << -100500;
       QTest::newRow("negativeNumber") << -777;
       QTest::newRow("zero") << 0;
       QTest::newRow("answerToTheUltimateQuestion") << 42;
       QTest::newRow("positiveNumber") << 666;
       QTest::newRow("largePositiveNumber") << 1000000000;
   }

   void popTest()
   {
       QFETCH(int, number);

       arrayStack->push(number);
       pointerStack->push(number);

       QVERIFY(arrayStack->pop() == number && pointerStack->pop() == number);
   }

   void manyElementsTest()
   {
       for (int i = 42; i <= 100500; i++)
       {
           arrayStack->push(i);
           pointerStack->push(i);
       }

       bool isRight = true;
       for (int i = 100500; i >= 42; i--)
       {
           isRight &= arrayStack->pop() == i;
           isRight &= pointerStack->pop() == i;
       }
       QVERIFY(isRight);
   }

private:
   Stack<int> *arrayStack = NULL;
   Stack<int> *pointerStack = NULL;
};
