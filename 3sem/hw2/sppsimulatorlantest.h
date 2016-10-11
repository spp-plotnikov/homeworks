#pragma once

#include "localnetwork.h"
#include "sppsimulatorlan.h"
#include <QtCore/QObject>
#include <QtTest/QtTest>


class SPPSimulatorLANTest : public QObject
{
    Q_OBJECT
public:
    explicit SPPSimulatorLANTest(QObject *parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        simulator = new SPPSimulatorLAN();
    }

    void cleanup()
    {
        delete simulator;
    }

    //  this test checks that all computers will get
    //  infected by viruses in finite number of steps
    void finiteTest()
    {
        const int sizeOfNetwork = 9;

        QList<int> *operatingSystems = new QList<int>;
        QList<QList<int>> *matrix = new QList<QList<int>>;


        for (int i = 0; i < sizeOfNetwork; i++)
        {
            operatingSystems->append(MacOS);

            QList<int> connections;
            if (i > 0)
            {
                connections.append(0);
            }
            else
            {
                for (int j = 1; j < sizeOfNetwork; j++)
                {
                    connections.append(j);
                }
            }

            matrix->append(connections);
        }

        network = new LocalNetwork(sizeOfNetwork, operatingSystems, matrix);
        simulator->setNetwork(network);

        for (int i = 0; i < 1000; i++)
        {
            simulator->nextStep();
        }

        bool areAllInfected = true;
        for (int i = 0; i < sizeOfNetwork; i++)
        {
            areAllInfected &= network->getStatusOfInfestationByIndex(i);
        }

        QVERIFY(areAllInfected);
    }

    // this test checks there are no auto-infections
    void autoInfectionTest()
    {
        QList<int> *operatingSystems = new QList<int>;
        operatingSystems->append(Windows);
        operatingSystems->append(Windows);

        QList<QList<int>> *matrix = new QList<QList<int>>;
        QList<int> emptyList;
        matrix->append(emptyList);
        matrix->append(emptyList);

        network = new LocalNetwork(2, operatingSystems, matrix);
        simulator->setNetwork(network);

        for (int i = 0; i < 1000; i++)
        {
            simulator->nextStep();
        }

        QVERIFY(!(network->getStatusOfInfestationByIndex(1)));
    }

    void correctOrderOfInfection()
    {
        const int sizeOfNetwork = 3;

        QList<int> *operatingSystems = new QList<int>;
        for (int i = 0; i < sizeOfNetwork; i++)
        {
            operatingSystems->append(Linux);
        }

        QList<QList<int>> *matrix = new QList<QList<int>>;
        QList<int> connections1;
        QList<int> connections2;
        QList<int> connections3;

        connections1.append(1);
        connections2.append(0);
        connections2.append(2);
        connections3.append(1);

        matrix->append(connections1);
        matrix->append(connections2);
        matrix->append(connections3);

        network = new LocalNetwork(sizeOfNetwork, operatingSystems, matrix);
        simulator->setNetwork(network);

        while (!(network->getStatusOfInfestationByIndex(2)))
        {
            simulator->nextStep();
        }

        QVERIFY(network->getStatusOfInfestationByIndex(1));
    }

private:
    SPPSimulatorLAN *simulator = nullptr;
    LocalNetwork *network = nullptr;

    enum {Windows, Linux, MacOS};
};
