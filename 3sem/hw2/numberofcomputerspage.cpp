#include "numberofcomputerspage.h"
#include "ui_numberofcomputerspage.h"

NumberOfComputersPage::NumberOfComputersPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::NumberOfComputersPage)
{
    ui->setupUi(this);

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeNumberOfComputers()));
}


void NumberOfComputersPage::changeNumberOfComputers()
{
    numberOfComputers = ui->comboBox->currentIndex() + 3;
}


NumberOfComputersPage::~NumberOfComputersPage()
{
    delete ui;
}
