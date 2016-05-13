#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "hashtable.h"
#include "hashfunction.h"
#include "optimalhashfunction.h"
#include "standardhashfunction.h"



class HashTableTest : public QObject
{
    Q_OBJECT
public:
    explicit HashTableTest(QObject *parent = 0) : QObject(parent) {}


private slots:
    void init()
    {
        table = new HashTable<QString>(standardHashFunction);
    }

    void addTest()
    {
        table->add(exampleString);
        QVERIFY(table->find(exampleString));
    }

    void removeTest()
    {
        table->add(exampleString);
        table->remove(exampleString);
        QVERIFY(!table->find(exampleString));
    }

    void changedFunctionTest()
    {
        table->add(exampleString);
        table->setHashFunction(optimalHashFunction);
        QVERIFY(table->find(exampleString));
    }

    void cleanup()
    {
        delete table;
    }

private:
    HashTable<QString> *table = nullptr;
    QString exampleString = "ololo";
    OptimalHashFunction optimalHashFunction;
    StandardHashFunction standardHashFunction;
};
