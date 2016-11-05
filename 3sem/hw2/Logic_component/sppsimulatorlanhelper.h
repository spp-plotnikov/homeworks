#pragma once

#include "localnetwork.h"

/*!
 * \author © Sasha Plotnikov Production, Ltd.
 * \brief this class provides the opportunity make next step in the LAN
 */
class SPPSimulatorLANHelper
{
public:
    /// \brief infection occurs discretely, by steps
    static void nextStep(LocalNetwork *network);

private:
    static bool tryToInfect(int index, LocalNetwork *network);
};
