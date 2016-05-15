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
    void init()
    {
    }

    void cleanup()
    {
    }
};
