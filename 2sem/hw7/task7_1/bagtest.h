#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "bag.h"


class BagTest : public QObject
{
   Q_OBJECT
public:
   explicit BagTest(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
        bag = new Bag;
   }

   void cleanup()
   {
        delete bag;
   }

   void addTest()
   {
       bag->add(777);
       QCOMPARE(bag->getCount(777), 1);
       QVERIFY(bag->find(777));
   }

   void removeTest()
   {
       bag->add(666);
       bag->remove(666);
       QCOMPARE(bag->getCount(666), 0);
       QVERIFY(!bag->find(666));
   }

   void countTest1()
   {
       for (int i = 0; i < 7; i++)
       {
           bag->add(1234);
       }
       QCOMPARE(bag->getCount(1234), 7);
       QVERIFY(bag->find(1234));
   }

   void countTest2()
   {
       for (int i = 0; i < 36; i++)
       {
           bag->add(-15);
       }
       for (int i = 0; i < 20; i++)
       {
           bag->remove(-15);
       }
       QCOMPARE(bag->getCount(-15), 16);
       QVERIFY(bag->find(-15));
   }

   void getContentTest()
   {
       for (int i = 0; i < 42; i++)
       {
           bag->add(i * 7);
       }

       int size = 0;
       int *array = bag->getContent(size);

       bool isCorrect = true;
       for (int i = 0; i < 42; i++)
       {
           isCorrect &= array[i] == i * 7;
       }

       delete array;
       QVERIFY(isCorrect);
   }

   void sizeOfArrayTest()
   {
       for (int i = 0; i < 42; i++)
       {
           bag->add(i * 4);
       }

       int size = 0;
       int *array = bag->getContent(size);
       delete array;

       QCOMPARE(size, 42);
   }

private:
   Bag *bag = nullptr;
};
