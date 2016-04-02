#pragma once

#include <QMainWindow>
#include <QSignalMapper>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void printExpression(const QString &text);
    void deletePreviousSymbol();
    void calculate();

private:
    Ui::MainWindow *ui;
    QSignalMapper *forPrinting = new QSignalMapper(this);
};
