#include "localnetwork.h"

LocalNetwork::LocalNetwork(const int numberOfComputers,
                           QList<int> *operatingSystems,
                           QList<QList<int>> *adjacencyMatrix) :
    numberOfComputers(numberOfComputers),
    operatingSystems(operatingSystems),
    adjacencyMatrix(adjacencyMatrix)
{
    isInfected[0] = true;
    for (int i = 1; i < numberOfComputers; i++)
    {
        isInfected[i] = false;
    }
}


int LocalNetwork::getNetworkSize() const
{
    return numberOfComputers;
}


LocalNetwork::~LocalNetwork()
{
    delete operatingSystems;
    delete adjacencyMatrix;
    delete isInfected;
}
