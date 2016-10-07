#pragma once

#include <QWizardPage>
#include <QComboBox>
#include <QLabel>

namespace Ui {
class SetOSPage;
}

class SetOSPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit SetOSPage(QWidget *parent = 0);

    void changeNumberOfComputers(const int newNumber);

    ~SetOSPage();

private:
    Ui::SetOSPage *ui;

    int numberOfComputers = 3;  //  starting value
};
