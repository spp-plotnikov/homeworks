#pragma once

#include "numberofcomputerspage.h"
#include "setospage.h"
#include "tablepage.h"
#include <QWizard>

namespace Ui {
class ConfigurationWizard;
}

class ConfigurationWizard : public QWizard
{
    Q_OBJECT

public:
    explicit ConfigurationWizard(QWidget *parent = 0);
    ~ConfigurationWizard();

private slots:
    // TODO: give this method name which is better
    void changeCurrentForm();

private:
    NumberOfComputersPage *numberOfComputersPage = new NumberOfComputersPage();
    SetOSPage *setOSPage = new SetOSPage();
    TablePage *tablePage = new TablePage();

    int previousId = 0;

    Ui::ConfigurationWizard *ui;
};

