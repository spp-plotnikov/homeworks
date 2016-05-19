#pragma once

#include <QMainWindow>

namespace Ui {
class BashQuotes;
}

class BashQuotes : public QMainWindow
{
    Q_OBJECT

public:
    explicit BashQuotes(QWidget *parent = 0);
    ~BashQuotes();

private:
    Ui::BashQuotes *ui;
};
