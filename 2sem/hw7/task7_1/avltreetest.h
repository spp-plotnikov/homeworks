#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "avltree.h"


class AVLTreeTest : public QObject
{
   Q_OBJECT
public:
   explicit AVLTreeTest(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
        tree = new AVLTree<int>;
   }

   void cleanup()
   {
        delete tree;
   }

   void addTest()
   {
       tree->add(777);
       QCOMPARE(tree->getCount(777), 1);
       QVERIFY(tree->isFound(777));
   }

   void removeTest()
   {
       tree->add(666);
       tree->remove(666);
       QCOMPARE(tree->getCount(666), 0);
       QVERIFY(!tree->isFound(666));
   }

   void countTest1()
   {
       for (int i = 0; i < 7; i++)
       {
           tree->add(1234);
       }
       QCOMPARE(tree->getCount(1234), 7);
       QVERIFY(tree->isFound(1234));
   }

   void countTest2()
   {
       for (int i = 0; i < 36; i++)
       {
           tree->add(-15);
       }
       for (int i = 0; i < 20; i++)
       {
           tree->remove(-15);
       }
       QCOMPARE(tree->getCount(-15), 16);
       QVERIFY(tree->isFound(-15));
   }

   void emptyTreeArrayTest()
   {
       int size = 0;
       int *array = tree->toPresentContentInArray(size);
       delete array;
       QCOMPARE(size, 0);
   }

   void treeToArrayTest1()
   {
       for (int i = 0; i < 42; i++)
       {
           tree->add(i * 7);
       }

       int size = 0;
       int *array = tree->toPresentContentInArray(size);

       bool isCorrect = true;
       for (int i = 0; i < 42; i++)
       {
           isCorrect &= array[i] == i * 7;
       }

       delete array;
       QVERIFY(isCorrect);
   }

   void treeToArrayTest2()
   {
       int expectedUnsorted[7] = {14, 10, 10, 84, 10, 83, 84};
       int expectedSorted[7] = {10, 10, 10, 14, 83, 84, 84};

       for (int i = 0; i < 7; i++)
       {
           tree->add(expectedUnsorted[i]);
       }

       int size = 0;
       int *array = tree->toPresentContentInArray(size);

       bool isCorrect = true;
       for (int i = 0; i < 7; i++)
       {
           isCorrect &= array[i] == expectedSorted[i];
       }

       delete array;
       QVERIFY(isCorrect);
   }

   void sizeOfArrayTest()
   {
       for (int i = 0; i < 42; i++)
       {
           tree->add(i * 4);
       }

       int size = 0;
       int *array = tree->toPresentContentInArray(size);
       delete array;

       QCOMPARE(size, 42);
   }

private:
   AVLTree<int> *tree = nullptr;
};
