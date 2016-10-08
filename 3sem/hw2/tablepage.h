#pragma once

#include <QWizardPage>

namespace Ui {
class TablePage;
}

class TablePage : public QWizardPage
{
    Q_OBJECT

public:
    explicit TablePage(QWidget *parent = 0);

    void generateTable(const int numberOfComputers);

    ~TablePage();

private slots:
    void changeCheckStateOfTransposeCell(int row, int column);

private:
    Ui::TablePage *ui;
};
