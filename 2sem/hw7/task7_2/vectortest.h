#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "vector.h"

class VectorTest : public QObject
{
    Q_OBJECT
public:
    explicit VectorTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void creationTest()
    {
        Vector<int, 32> vector;
        QVERIFY(vector.isNull());
    }

    void copyTest()
    {
        Vector<int, 16> vector1;
        for (int i = 0; i < 16; i++)
        {
            vector1[i] = i * 7;
        }
        Vector<int, 16> vector2(vector1);

        bool isCorrect = true;
        for (int i = 0; i < 16; i++)
        {
            isCorrect &= vector2[i] == i * 7;
        }

        QVERIFY(isCorrect);
    }

    void subtractionTest()
    {
        Vector<int, 42> vector1;
        for (int i = 0; i < 42; i++)
        {
            vector1[i] = i * 3;
        }

        Vector<int, 42> vector2;
        for (int i = 0; i < 42; i++)
        {
            vector2[i] = i * 3 + 1;
        }

        Vector<int, 42> vector3 = vector1 - vector2;

        bool isCorrect = true;
        for (int i = 0; i < 42; i++)
        {
            isCorrect &= vector3[i] == -1;
        }

        QVERIFY(isCorrect);
    }

    void additionTest()
    {
        Vector<int, 12> vector1;
        for (int i = 0; i < 12; i++)
        {
            vector1[i] = i;
        }

        Vector<int, 12> vector2;
        for (int i = 0; i < 12; i++)
        {
            vector2[i] = 11 - i;
        }

        Vector<int, 12> vector3 = vector2 + vector1;

        bool isCorrect = true;
        for (int i = 0; i < 12; i++)
        {
            isCorrect &= vector3[i] == 11;
        }

        QVERIFY(isCorrect);
    }

    void assignmentOperatorTest()
    {
        Vector<int, 2> vector1;
        vector1[0] = 7;
        vector1[1] = -9;

        Vector<int, 2> vector2;
        vector2 = vector1;

        QCOMPARE(vector2[0], 7);
        QCOMPARE(vector2[1], -9);
    }

    void scalarMultiplicationTest()
    {
        Vector<int, 3> vector1;
        vector1[0] = 6;
        vector1[1] = -2;
        vector1[2] = 13;

        Vector<int, 3> vector2;
        vector2[0] = -3;
        vector2[1] = 7;
        vector2[2] = 1;

        QCOMPARE(vector1 * vector2, -19);
    }

    void squareBracketsTest()
    {
        Vector<int, 77> vector;
        vector[23] = 15;
        QCOMPARE(vector[23], 15);
    }

    void exceptionTest()
    {
        Vector<float, 19> vector;
        bool exception = false;

        try
        {
            vector[19];
        }
        catch (Vector<float, 19>::OutOfRangeException &)
        {
            exception = true;
        }

        QVERIFY(exception);
    }
};


QTEST_MAIN(VectorTest)
