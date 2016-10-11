#pragma once

#include "numberofcomputerspage.h"
#include "sppsimulatorlan.h"
#include "localnetwork.h"
#include "setospage.h"
#include "tablepage.h"
#include <QWizard>

namespace Ui {
class ConfigurationWizard;
}

/*!
 * \author © Sasha Plotnikov Production, Ltd.
 * \brief The ConfigurationWizard helps generate networks for S P P  Simulator of LAN
 * \details You can generate networks which contains only 3-9 computers
 */
class ConfigurationWizard : public QWizard
{
    Q_OBJECT

public:
    /// \param owner is the simulator which gets network from this wizard
    explicit ConfigurationWizard(SPPSimulatorLAN &owner, QWidget *parent = 0);
    ~ConfigurationWizard();

private slots:
    void changeCurrentForm();
    void runSPPSimulatorLAN();

private:
    NumberOfComputersPage *numberOfComputersPage = new NumberOfComputersPage();
    SetOSPage *setOSPage = new SetOSPage();
    TablePage *tablePage = new TablePage();

    int previousId = 0;
    SPPSimulatorLAN &simulator;

    Ui::ConfigurationWizard *ui;
};

