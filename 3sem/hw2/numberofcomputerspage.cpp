#include "numberofcomputerspage.h"
#include "ui_numberofcomputerspage.h"

NumberOfComputersPage::NumberOfComputersPage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::NumberOfComputersPage)
{
    ui->setupUi(this);

    //connect((ui->comboBox, QComboBox:))
}

NumberOfComputersPage::~NumberOfComputersPage()
{
    delete ui;
}
