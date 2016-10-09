#pragma once

#include <QList>

class LocalNetwork
{
public:
    LocalNetwork(const int numberOfComputers, QList<int> *operatingSystems,
                 QList<QList<int> > *adjacencyMatrix);

    int getNetworkSize() const;
    int getOSByIndex(int index) const;
    QList<int> getConnectionsByIndex(int index) const;

    ~LocalNetwork();
private:
    const int numberOfComputers;
    QList<int> *operatingSystems = nullptr;
    QList<QList<int>> *adjacencyMatrix = nullptr;
    QList<bool> isInfected;
};
