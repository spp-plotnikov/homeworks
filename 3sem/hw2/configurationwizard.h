#pragma once

#include "numberofcomputerspage.h"
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

private:
    QWizardPage *numberOfComputersPage = new NumberOfComputersPage();

    Ui::ConfigurationWizard *ui;
};

