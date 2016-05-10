#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <cstdlib>
#include <ctime>
#include "set.h"


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
       set->add(randomNumber);
       QVERIFY(set->find(randomNumber));
   }

   void deleteTest()
   {
       set->add(randomNumber);
       set->remove(randomNumber);
       QVERIFY(!set->find(randomNumber));
   }

   void containsOneElementTest()
   {
       set->add(randomNumber);
       int size = 0;
       int *array = set->getContent(size);
       bool contains = array[0] == randomNumber;
       delete []array;
       QVERIFY(contains);
   }

   void containsManyElements()
   {
       srand(time(0));
       int quantity = 20 + rand() % 200;
       for (int i = quantity; i > 0 ; i--)
       {
           threeMultiples = i * 3;
           set->add(threeMultiples);
       }

       int size = 0;
       int *array = set->getContent(size);
       bool isCorrect = true;
       for (int i = 1; i <= quantity; i++)
       {
           isCorrect &= array[i - 1] == i * 3;
       }

       delete []array;
       QVERIFY(isCorrect);
   }

   void correctSizeTest()
   {
       int expectedSize = randomNumber;
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
           twoMultiples = i * 2;
           set->add(twoMultiples);
       }

       Set<int> otherSet;
       for (int i = 0; i < 20; i++)
       {
           threeMultiples = i * 3;
           otherSet.add(threeMultiples);
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
           twoMultiples = i * 2;
           set->add(twoMultiples);
       }

       Set<int> otherSet;
       for (int i = 0; i < 20; i++)
       {
           threeMultiples = i * 3;
           otherSet.add(threeMultiples);
       }

       set->setUnion(otherSet);
       int size = 0;
       int *array = set->getContent(size);
       delete []array;
       QVERIFY(size == 40);
   }

private:
   Set<int> *set = nullptr;
   int randomNumber = 20 + rand() % 200;

   int threeMultiples = 0;
   int twoMultiples = 0;
};
