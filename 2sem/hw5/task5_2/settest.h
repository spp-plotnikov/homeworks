#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <ctime>
#include "set.h"

srand(time(0));

class SetTest : public QObject
{
   Q_OBJECT
public:
   explicit SetTest(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
        set = new Set<int>;
   }

   void cleanup()
   {
        delete set;
   }

   void addTest()
   {
       set->add(2016);
       QVERIFY(set->find(2016));
   }

   void deleteTest()
   {
       set->add(2016);
       set->remove(2016);
       QVERIFY(!set->find(2016));
   }

   void containsOneElementTest()
   {
       set->add(42);
       int size = 0;
       int *array = set->getContent(size);
       bool contains = array[0] == 42;
       delete []array;
       QVERIFY(contains);
   }

   void containsManyElements()
   {
       int quantity = 20 + rand() % 200;
       for (int i = quantity; i > 0 ; i--)
       {
           set->add(i * 3);
       }

       int size = 0;
       int *array = set->getContent(size);
       bool isCorrect = true;
       for (int i = 1; i <= quantity; i++)
       {
           isCorrect &= array[i] == i * 3;
       }

       delete []array;
       QVERIFY(isCorrect);
   }

   void correctSizeTest()
   {
       int expectedSize = 20 + rand() % 200;
       for (int i = 0; i < expectedSize; i++)
       {
           set->add(i);
       }

       int actualSize = 0;
       int *array = set->getContent(actualSize);
       delete []array;
       QCOMPARE(actualSize, expectedSize);
   }

   void setIntersectionTest()
   {
       for (int i = 0; i < 30; i++)
       {
           set->add(i * 2);
       }

       Set otherSet;
       for (int i = 0; i < 20; i++)
       {
           otherSet.add(i * 3);
       }

       set->setIntersection(otherSet);
       int size = 0;
       int *array = set->getContent(size);
       bool isCorrect = true;
       for (int i = 0; i < size; i++)
       {
           isCorrect &= array[i] % 6 == 0;
       }

       delete []array;
       QVERIFY(isCorrect);
   }

   void setUnionTest()
   {
       for (int i = 0; i < 30; i++)
       {
           set->add(i * 2);
       }

       Set otherSet;
       for (int i = 0; i < 20; i++)
       {
           otherSet.add(i * 3);
       }

       set->setUnion(otherSet);
       int size = 0;
       int *array = set->getContent(size);
       delete []array;
       QVERIFY(size == 50);
   }

private:
   Set<int> *set = nullptr;
};
