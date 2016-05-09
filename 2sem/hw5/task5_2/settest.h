#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
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

private:
   Set<int> *set = nullptr;
};
