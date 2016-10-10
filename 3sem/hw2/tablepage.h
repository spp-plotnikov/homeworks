#pragma once

#include <QWizardPage>
#include <QList>

namespace Ui {
class TablePage;
}

class TablePage : public QWizardPage
{
    Q_OBJECT

public:
    explicit TablePage(QWidget *parent = 0);

    void generateTable(const int numberOfComputers);
    QList<QList<int> > *getAdjacencyMatrix() const;
    bool validatePage();

    ~TablePage();

private slots:
    void changeCheckStateOfTransposeCell(int row, int column);
    void updateNextButton();

private:
    void traversal(int index, QList<bool> &isUsed);
    Ui::TablePage *ui;
    bool isCorrectTableFilling = false;
};
