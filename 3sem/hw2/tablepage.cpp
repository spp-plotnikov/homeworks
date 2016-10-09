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
    isCorrectTableFilling = false;

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

    connect(ui->tableWidget, SIGNAL(cellClicked(int,int)),
            this, SLOT(changeCheckStateOfTransposeCell(int, int)));
    connect(ui->tableWidget, SIGNAL(cellClicked(int,int)),
            this, SLOT(updateNextButton()));
}


void TablePage::changeCheckStateOfTransposeCell(int row, int column)
{
    if (row == column)
        return;
    if (ui->tableWidget->item(row, column)->checkState() == Qt::Unchecked)
    {
        ui->tableWidget->item(column, row)->setCheckState(Qt::Unchecked);
    }
    else
    {
        ui->tableWidget->item(column, row)->setCheckState(Qt::Checked);
    }
}


void TablePage::updateNextButton()
{
    for (int i = 0; i < ui->tableWidget->columnCount(); i++)
    {
        bool computerIsConnected = false;
        for (int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            if (i != j && ui->tableWidget->item(i, j)->checkState() == Qt::Checked)
            {
                computerIsConnected = true;
                break;
            }
        }
        if (!computerIsConnected)
        {
            isCorrectTableFilling = false;
            return;
        }
    }

    isCorrectTableFilling = true;
}


QList<QList<int>>* TablePage::getAdjacencyMatrix() const
{
    QList<QList<int>> *adjacencyMatrix = new QList<QList<int>>();

    for (int i = 0; i < ui->tableWidget->columnCount(); i++)
    {
        QList<int> computerWithThisIndex;
        for (int j = 0; j  < ui->tableWidget->columnCount(); j++)
        {
            if (i != j && ui->tableWidget->item(i, j)->checkState() == Qt::Checked)
            {
                computerWithThisIndex.append(j);
            }
        }
        adjacencyMatrix->append(computerWithThisIndex);
    }

    return adjacencyMatrix;
}


bool TablePage::validatePage()
{
    return isCorrectTableFilling;
}


TablePage::~TablePage()
{
    delete ui;
}
