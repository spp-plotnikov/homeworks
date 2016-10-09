#include "localnetwork.h"

LocalNetwork::LocalNetwork(const int numberOfComputers,
                           QList<int> *operatingSystems,
                           QList<QList<int>> *adjacencyMatrix) :
    numberOfComputers(numberOfComputers),
    operatingSystems(operatingSystems),
    adjacencyMatrix(adjacencyMatrix)
{
    isInfected.append(true);
    for (int i = 1; i < numberOfComputers; i++)
    {
        isInfected.append(false);
    }
}


int LocalNetwork::getNetworkSize() const
{
    return numberOfComputers;
}


int LocalNetwork::getOSByIndex(const int index) const
{
    return operatingSystems->at(index);
}


LocalNetwork::~LocalNetwork()
{
    delete operatingSystems;
    delete adjacencyMatrix;
}
