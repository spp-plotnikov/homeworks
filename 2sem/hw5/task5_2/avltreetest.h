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
       QVERIFY(tree->isFound(777));
   }

   void removeTest()
   {
       tree->add(777);
       tree->remove(777);
       QVERIFY(!tree->isFound(777));
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
