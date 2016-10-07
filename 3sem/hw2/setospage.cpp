#include "setospage.h"
#include "ui_setospage.h"

SetOSPage::SetOSPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::SetOSPage)
{
    ui->setupUi(this);
}


void SetOSPage::changeNumberOfComputers(const int newNumber)
{
    numberOfComputers = newNumber;
    foreach (QObject *thisItem, ui->formLayout->children())
    {
        delete thisItem;
    }

    for (int i = 0; i < numberOfComputers; i++)
    {
        //QLabel *newLabel = new QLabel("ololo");
        QComboBox *newCombo = new QComboBox();
        ui->formLayout->addRow("Computer №" + QString::setNum(i + 1), newCombo);
    }
}


SetOSPage::~SetOSPage()
{
    changeNumberOfComputers(0);
    delete ui;
}
