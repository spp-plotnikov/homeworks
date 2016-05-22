#pragma once

#include <QMainWindow>

namespace Ui {
class ServerSPP;
}

class ServerSPP : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerSPP(QWidget *parent = 0);
    ~ServerSPP();

private:
    Ui::ServerSPP *ui;
};
