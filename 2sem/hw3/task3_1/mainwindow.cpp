#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, &QSlider::valueChanged,
            ui->progressBar, &QProgressBar::setValue);
    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");
}

MainWindow::~MainWindow()
{
    delete ui;
}
