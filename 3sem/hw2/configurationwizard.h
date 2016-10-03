#pragma once

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
    Ui::ConfigurationWizard *ui;
};

