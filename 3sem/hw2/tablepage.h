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
    bool validatePage();

    ~TablePage();

private slots:
    void changeCheckStateOfTransposeCell(int row, int column);
    void updateNextButton();

private:
    Ui::TablePage *ui;
    bool isCorrectTableFilling = false;
};
