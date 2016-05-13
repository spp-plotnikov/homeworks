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

private:
   void setType(int type)
   {
       if (type)
           currentList = arrayList;
       else
           currentList = pointerList;
   }

   List *arrayList = nullptr;
   List *pointerList = nullptr;
   List *currentList = nullptr;
};
