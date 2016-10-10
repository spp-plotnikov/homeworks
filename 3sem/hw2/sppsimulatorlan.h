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
    void setNetwork(LocalNetwork *thisNetwork);
    void nextStep();
    ~SPPSimulatorLAN();

private slots:
    void makeMove();

private:
    bool tryToInfect(int index);
    void fillTable();
    void updateTable();

    LocalNetwork *network = nullptr;

    Ui::SPPSimulatorLAN *ui;

    enum {Windows, Linux, MacOS};
};
