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
       tree->add(&tripleSeven);
       QVERIFY(tree->isFound(&tripleSeven));
   }

   void removeTest()
   {
       tree->add(&tripleSeven);
       tree->remove(&tripleSeven);
       QVERIFY(!tree->isFound(&tripleSeven));
   }

   void emptyTreeArrayTest()
   {
       int size = 0;
       int *array = tree->toPresentContentInArray(size);
       delete array;
       QCOMPARE(size, 0);
   }

   void treeToArrayTest()
   {
       int sevenMultiples = 0;
       for (int i = 0; i < 42; i++)
       {
           sevenMultiples = i * 7;
           tree->add(&sevenMultiples);
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

   void sizeOfArrayTest()
   {
       int fourMultiples = 0;
       for (int i = 0; i < 42; i++)
       {
           fourMultiples = i * 4;
           tree->add(&fourMultiples);
       }

       int size = 0;
       int *array = tree->toPresentContentInArray(size);
       delete array;

       QCOMPARE(size, 42);
   }

private:
   AVLTree<int> *tree = nullptr;
   const int tripleSeven = 777;
};
