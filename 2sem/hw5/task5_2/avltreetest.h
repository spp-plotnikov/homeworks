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

private:
   AVLTree<int> *tree = nullptr;
};
