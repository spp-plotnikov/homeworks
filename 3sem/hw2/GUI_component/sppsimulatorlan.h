#pragma once

#include "Logic_component/localnetwork.h"
#include <QMainWindow>


namespace Ui {
class SPPSimulatorLAN;
}

/*!
 * \author © Sasha Plotnikov Production, Ltd.
 * \brief this class provides the opportunity to simulate
 * the process of virus infection in the local network
 * \warning before simulating the network,
 * specify this network using the method setNetwork()
 */
class SPPSimulatorLAN : public QMainWindow
{
    Q_OBJECT

public:
    explicit SPPSimulatorLAN(QWidget *parent = 0);
    /// \brief before using, set the network using this method
    void setNetwork(LocalNetwork *thisNetwork);
    ~SPPSimulatorLAN();

private slots:
    void makeMove();

private:
    void fillTable();
    void updateTable();

    LocalNetwork *network = nullptr;

    Ui::SPPSimulatorLAN *ui;
};
