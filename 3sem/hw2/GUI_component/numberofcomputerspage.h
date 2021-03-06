#pragma once

#include <QWizardPage>

namespace Ui {
class NumberOfComputersPage;
}

/// \brief this page allows to choose quantity of computers in your LAN
class NumberOfComputersPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit NumberOfComputersPage(QWidget *parent = 0);

    int getNumberOfComputers() const
    {
        return numberOfComputers;
    }

    ~NumberOfComputersPage();

private:
    Ui::NumberOfComputersPage *ui;

    int numberOfComputers = 3;  //  starting value

private slots:
    void changeNumberOfComputers();
};
