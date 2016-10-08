#include "tablepage.h"
#include "ui_tablepage.h"

TablePage::TablePage(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::TablePage)
{
    ui->setupUi(this);
}


void TablePage::generateTable(const int numberOfComputers)
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(numberOfComputers);
    ui->tableWidget->setRowCount(numberOfComputers);

    for (int i = 0; i < numberOfComputers; i++)
    {
        for (int j = 0; j < numberOfComputers; j++)
        {
            if (i != j)
            {

                ui->tableWidget->setItem(i, j, new QTableWidgetItem());
                ui->tableWidget->item(i,j)->data(Qt::CheckStateRole);
                ui->tableWidget->item(i,j)->setCheckState(Qt::Unchecked);
            }
        }
    }

    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->resizeColumnsToContents();
}


TablePage::~TablePage()
{
    delete ui;
}
