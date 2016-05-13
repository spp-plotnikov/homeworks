#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "arithmetictree.h"


class ArithmeticTreeTest : public QObject
{
   Q_OBJECT
public:
   explicit ArithmeticTreeTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void testOfResult_data()
    {
        QTest::addColumn<QString>("fileName");
        QTest::addColumn<double>("expectedResult");

        QTest::newRow("trivialTest") << "trivialTest.spp_test_module" << 4.0;
        QTest::newRow("usualTest") << "usualTest.spp_test_module" << 7.5;
        QTest::newRow("hardTest") << "hardTest.spp_test_module" << 550.4;
    }

    void testOfResult()
    {
        QFETCH(QString, fileName);
        QFETCH(double, expectedResult);

        FILE *testFile = fopen(fileName.toLocal8Bit().constData(), "r");
        tree = new ArithmeticTree(testFile);
        double actualResult = tree->calculateTree();

        delete tree;
        fclose(testFile);
        QCOMPARE(actualResult, expectedResult);
    }

private:
    ArithmeticTree *tree = nullptr;
};
