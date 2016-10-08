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
    while(QLayoutItem *item = ui->formLayout->itemAt(0))
    {
        ui->formLayout->removeItem(item);
        ui->formLayout->removeWidget(item->widget());
        delete item->widget();
        delete item;
        ui->formLayout->update();
    }

    numberOfComputers = newNumber;

    QString temp;
    for (int i = 0; i < numberOfComputers; i++)
    {
        temp.setNum(i + 1);
        temp = QString("Computer №") + temp;

        QComboBox *newCombo = new QComboBox();
        newCombo->addItem("Windows");
        newCombo->addItem("Linux");
        newCombo->addItem("Mac OS");

        ui->formLayout->addRow(temp, newCombo);
    }
}


SetOSPage::~SetOSPage()
{
    changeNumberOfComputers(0);
    delete ui;
}
