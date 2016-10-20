#pragma once

#include "Logic_component/sppsimulatorlanhelper.h"
#include "operatingsystemsenumeration.h"
#include "localnetwork.h"
#include <QtCore/QObject>
#include <QtTest/QtTest>


class SPPSimulatorLANHelperTest : public QObject
{
    Q_OBJECT
public:
    explicit SPPSimulatorLANHelperTest(QObject *parent = 0) : QObject(parent) {}

private slots:

    //  this test checks that all computers will get
    //  infected by viruses in finite number of steps
    void finiteTest()
    {
        const int sizeOfNetwork = 9;

        QList<int> *operatingSystems = new QList<int>;
        QList<QList<int>> *matrix = new QList<QList<int>>;


        for (int i = 0; i < sizeOfNetwork; i++)
        {
            operatingSystems->append(OS::MacOS);

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

        for (int i = 0; i < 1000; i++)
        {
            SPPSimulatorLANHelper::nextStep(network);
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
        operatingSystems->append(OS::Windows);
        operatingSystems->append(OS::Windows);

        QList<QList<int>> *matrix = new QList<QList<int>>;
        QList<int> emptyList;
        matrix->append(emptyList);
        matrix->append(emptyList);

        network = new LocalNetwork(2, operatingSystems, matrix);

        for (int i = 0; i < 1000; i++)
        {
            SPPSimulatorLANHelper::nextStep(network);
        }

        QVERIFY(!(network->getStatusOfInfestationByIndex(1)));
    }

    void correctOrderOfInfection()
    {
        const int sizeOfNetwork = 3;

        QList<int> *operatingSystems = new QList<int>;
        for (int i = 0; i < sizeOfNetwork; i++)
        {
            operatingSystems->append(OS::Linux);
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

        while (!(network->getStatusOfInfestationByIndex(2)))
        {
            SPPSimulatorLANHelper::nextStep(network);
        }

        QVERIFY(network->getStatusOfInfestationByIndex(1));
    }


    /*  The network used in the test:
     *
     *        3   5
     *       / \ /
     *      2———4
     *     /     \
     *    1       6——7
     */
    void nonTrivialNetwork()
    {
        const int sizeOfNetwork = 7;

        QList<int> *operatingSystems = new QList<int>;
        for (int i = 0; i < sizeOfNetwork; i++)
        {
            operatingSystems->append(OS::OnlyForTestsOS);
        }

        QList<QList<int>> *matrix = new QList<QList<int>>;
        QList<int> connections[sizeOfNetwork];

        connections[0].append(1);
        connections[1].append(0);
        connections[1].append(2);
        connections[1].append(3);
        connections[2].append(1);
        connections[2].append(3);
        connections[3].append(1);
        connections[3].append(4);
        connections[3].append(5);
        connections[4].append(3);
        connections[5].append(3);
        connections[5].append(6);
        connections[6].append(5);

        for (int i = 0; i < sizeOfNetwork; i++)
        {
            matrix->append(connections[i]);
        }
        network = new LocalNetwork(sizeOfNetwork, operatingSystems, matrix);


        /*  Step 1:
         *
         *        3   5
         *       / \ /
         *      i———4
         *     /     \
         *    i       6——7
         */
        SPPSimulatorLANHelper::nextStep(network);
        QVERIFY(network->getStatusOfInfestationByIndex(1));
        for (int i = 2; i < sizeOfNetwork; i++)
        {
            QVERIFY(!(network->getStatusOfInfestationByIndex(i)));
        }


        /*  Step 2:
         *
         *        i   5
         *       / \ /
         *      i———i
         *     /     \
         *    i       6——7
         */
        SPPSimulatorLANHelper::nextStep(network);
        QVERIFY(network->getStatusOfInfestationByIndex(1));
        QVERIFY(network->getStatusOfInfestationByIndex(2));
        QVERIFY(network->getStatusOfInfestationByIndex(3));
        for (int i = 4; i < sizeOfNetwork; i++)
        {
            QVERIFY(!(network->getStatusOfInfestationByIndex(i)));
        }


        /*  Step 3:
         *
         *        i   i
         *       / \ /
         *      i———i
         *     /     \
         *    i       i——7
         */
        SPPSimulatorLANHelper::nextStep(network);
        QVERIFY(!(network->getStatusOfInfestationByIndex(6)));
        for (int i = 0; i < sizeOfNetwork - 1; i++)
        {
            QVERIFY(network->getStatusOfInfestationByIndex(i));
        }


        /*  Step 4:
         *
         *        i   i
         *       / \ /
         *      i———i
         *     /     \
         *    i       i——i
         */
        SPPSimulatorLANHelper::nextStep(network);
        for (int i = 0; i < sizeOfNetwork; i++)
        {
            QVERIFY(network->getStatusOfInfestationByIndex(i));
        }
    }

private:
    LocalNetwork *network = nullptr;
};
