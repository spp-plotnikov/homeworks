#pragma once

#include "localnetwork.h"
#include <QMainWindow>


namespace Ui {
class SPPSimulatorLAN;
}

class SPPSimulatorLAN : public QMainWindow
{
    Q_OBJECT

public:
    explicit SPPSimulatorLAN(QWidget *parent = 0);
    void setNetworkAndRun(LocalNetwork *thisNetwork);
    ~SPPSimulatorLAN();

private:
    LocalNetwork *network = nullptr;

    Ui::SPPSimulatorLAN *ui;
};
