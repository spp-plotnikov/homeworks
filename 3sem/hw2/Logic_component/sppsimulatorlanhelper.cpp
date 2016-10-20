#include "operatingsystemsenumeration.h"
#include "sppsimulatorlanhelper.h"
#include <ctime>


void SPPSimulatorLANHelper::nextStep(LocalNetwork *network)
{
    QList<int> listOfNewInfectedComputers;
    for (int i = 0; i < network->getNetworkSize(); i++)
    {
        if (network->getStatusOfInfestationByIndex(i))
        {
            QList<int> connections(network->getConnectionsByIndex(i));
            for (int j = 0; j < connections.size(); j++)
            {
                if (tryToInfect(connections[j], network))
                    listOfNewInfectedComputers.append(connections[j]);
            }
        }
    }

    for (int i = 0; i < listOfNewInfectedComputers.size(); i++)
    {
        network->setInfection(listOfNewInfectedComputers[i]);
    }
}


bool SPPSimulatorLANHelper::tryToInfect(int index, LocalNetwork *network)
{
    if (network->getStatusOfInfestationByIndex(index))
        return true;

    srand(rand());
    const int randomNumber = 1 + rand() % 101;
    bool infected = false;
    switch (network->getOSByIndex(index))
    {
    case OS::Windows:
    {
        if (randomNumber < 60)  //  60% is the likelihood of Contracting the virus for Windows
            infected = true;
        break;
    }
    case OS::Linux:
    {
        if (randomNumber < 40)  //  40% is the likelihood of Contracting the virus for Linux
            infected = true;
        break;
    }
    case OS::MacOS:
    {
        if (randomNumber < 20)  //  20% is the likelihood of Contracting the virus for OS X
            infected = true;
        break;
    }
    default:
    {
        infected = true;
        break;
    }
    }

    return infected;
}
