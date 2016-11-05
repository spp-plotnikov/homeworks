#pragma once

#include <QWizardPage>
#include <QComboBox>
#include <QList>

namespace Ui {
class SetOSPage;
}

/// \brief this page allows to choose OS for each computer in your LAN
class SetOSPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit SetOSPage(QWidget *parent = 0);

    /// \brief you can change number of computers
    void changeNumberOfComputers(const int newNumber);
    /// \returns list of OS for each comp; 0 - Windows, 1 - Linux, 2 - MacOS
    QList<int>* getListOfOperatingSystems() const;

    ~SetOSPage();

private:
    Ui::SetOSPage *ui;

    int numberOfComputers = 3;  //  starting value
};
