#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include <QString>
#include <math.h>
#include "calculator.h"


class CalculatorTest : public QObject
{
   Q_OBJECT
public:
   explicit CalculatorTest(QObject *parent = 0) : QObject(parent) {}

private slots:
   void init()
   {
       calculator = new Calculator;
   }

   void cleanup()
   {
       delete calculator;
   }

   void standardExampleFromCommentsInConsole()
   {
       double result = calculator->calculate("1 + 2 * (15 - 4) / 2,5 * 255 + 3,25");
       QVERIFY(isEqual(result, 2248.25));
   }

   void oneElementTest_data()
   {
       QTest::addColumn<QString>("string");
       QTest::addColumn<double>("number");

       QTest::newRow("largeNegativeDouble") << "-100500,12345" << -100500.12345;
       QTest::newRow("negativeDouble") << "-777,777" << -777.777;
       QTest::newRow("largeNegativeInt") << "-100500" << -100500.00000;
       QTest::newRow("negativeInt") << "-777" << -777.000000;
       QTest::newRow("zero") << "0" << 0.0;
       QTest::newRow("answerToTheUltimateQuestion") << "42" << 42.000000;
       QTest::newRow("positiveDouble") << "666,777" << 666.777;
       QTest::newRow("positiveInt") << "666" << 666.000000;
       QTest::newRow("largePositiveDouble") << "12345678,999" << 12345678.999;
       QTest::newRow("largePositiveInt") << "10000000" << 10000000.00000;
   }

   void oneElementTest()
   {
       QFETCH(double, number);
       QFETCH(QString, string);

       double result = calculator->calculate(string.toLocal8Bit().data());
       QVERIFY(isEqual(result, number));
   }

   void priorityTest()
   {
       QVERIFY(isEqual(calculator->calculate("2 + 2 * 2"), 6.0));
   }

   void parenthesesTest()
   {
       QVERIFY(isEqual(calculator->calculate("8 - (10 - 7)"), 5.0));
   }

   void doubleEasyTest()
   {
       QVERIFY(isEqual(calculator->calculate("0,5 * 0,5"), 0.25));
   }

private:
   /// \brief checks two numbers of type Double for equality
   bool isEqual(double arg1, double arg2)
   {
       double epsilon = 0.000001;  //  infinitesimal
       if (fabs(arg1 - arg2) < epsilon)
           return true;
       else
           return false;
   }

   Calculator *calculator = NULL;
};
