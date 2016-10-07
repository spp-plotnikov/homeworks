#pragma once

#include <QWizardPage>

namespace Ui {
class NumberOfComputersPage;
}

class NumberOfComputersPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit NumberOfComputersPage(QWidget *parent = 0);

    int getNumberOfComputrs() const
    {
        return numberOfComputers;
    }

    ~NumberOfComputersPage();

private:
    Ui::NumberOfComputersPage *ui;

    int numberOfComputers = 3;  //  starting value
};
