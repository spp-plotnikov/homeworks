#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "list.h"
#include "arraylist.h"
#include "pointerlist.h"

class ListTest : public QObject
{
   Q_OBJECT
public:
   explicit ListTest(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
       arrayList = new ArrayList();
       pointerList = new PointerList();
   }

   void cleanup()
   {
       delete arrayList;
       delete pointerList;
   }

   void addTest_data()
   {
       QTest::addColumn<int>("number");

       QTest::newRow("largeNegativeNumber") << -100500;
       QTest::newRow("negativeNumber") << -777;
       QTest::newRow("zero") << 0;
       QTest::newRow("answerToTheUltimateQuestion") << 42;
       QTest::newRow("positiveNumber") << 666;
       QTest::newRow("largePositiveNumber") << 1000000000;
   }

   void addTest()
   {
       QFETCH(int, number);

       arrayList->add(number);
       pointerList->add(number);
       QVERIFY(arrayList->isFound(number) && pointerList->isFound(number));
   }

   void removeTest_data()
   {
       QTest::addColumn<int>("number");

       QTest::newRow("largeNegativeNumber") << -100500;
       QTest::newRow("negativeNumber") << -777;
       QTest::newRow("zero") << 0;
       QTest::newRow("answerToTheUltimateQuestion") << 42;
       QTest::newRow("positiveNumber") << 666;
       QTest::newRow("largePositiveNumber") << 1000000000;
   }

   void removeTest()
   {
       QFETCH(int, number);

       arrayList->add(number);
       pointerList->add(number);

       arrayList->remove(number);
       pointerList->remove(number);

       QVERIFY(!arrayList->isFound(number) && !pointerList->isFound(number));
   }

private:
   List *arrayList = NULL;
   List *pointerList = NULL;
};
