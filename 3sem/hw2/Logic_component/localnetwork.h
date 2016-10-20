#pragma once

#include <QList>


/*!
 * \author © Sasha Plotnikov Production, Ltd.
 * \brief The class represents LAN
 * \details You can choose the number of computers,
 * their matrix compounds, their operating systems
 * and the status of the infestation
 */
class LocalNetwork
{
public:
    LocalNetwork(const int numberOfComputers, QList<int> *operatingSystems,
                 QList<QList<int>> *adjacencyMatrix);

    /// \returns quantity of computers in this network
    int getNetworkSize() const;
    /// \returns OS of comp. with this index; 0 - Windows, 1 - Linux, 2 - MacOS
    int getOSByIndex(int index) const;
    /// \returns list of the indexes of computers connected to computer with given index
    QList<int> getConnectionsByIndex(int index) const;
    /// \returns true if comp with this index is infected, false otherwise
    bool getStatusOfInfestationByIndex(int index) const;
    /// \brief marks as infected computer with this index
    void setInfection(int index);

    ~LocalNetwork();

private:
    const int numberOfComputers;
    QList<int> *operatingSystems = nullptr;
    QList<QList<int>> *adjacencyMatrix = nullptr;
    QList<bool> isInfected;
};
