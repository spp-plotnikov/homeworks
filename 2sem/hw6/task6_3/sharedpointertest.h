#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "sharedpointer.h"


class SharedPointerTest : public QObject
{
    Q_OBJECT
public:
    explicit SharedPointerTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    { 
    }


    void cleanup()
    {
    }
};

