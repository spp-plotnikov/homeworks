#pragma once

#include <QWizardPage>
#include <QList>

namespace Ui {
class TablePage;
}

/// \brief this page is for creating adjacency matrix
class TablePage : public QWizardPage
{
    Q_OBJECT

public:
    explicit TablePage(QWidget *parent = 0);

    /// \brief generates empty matrix NxN, N is numberOfComputers
    void generateTable(const int numberOfComputers);
    /// \returns list of connected computers for each computer
    QList<QList<int> > *getAdjacencyMatrix() const;
    /// \returns true if there is only one component it the graph
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
