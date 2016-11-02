#include "gamegui.h"
#include "ui_gamegui.h"
#include "cannon.h"

#include <QPolygon>



GameGUI::GameGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameGUI)
{
    ui->setupUi(this);

    statusBar()->showMessage("© Sasha Plotnikov Production, Ltd.");
    statusBar()->setEnabled(false);
    setWindowIcon(QIcon(":/new/prefix1/logoSPP.ico"));

    ui->gameField->setScene(scene);
    setLandscape();
}


void GameGUI::setLandscape()
{
    // hard coded

    const int realWidth = ui->gameField->width() - 3;
    const int realHeight = ui->gameField->height() - 3;
    scene->setSceneRect(QRect(0, 0, realWidth, realHeight));

    QPolygon landscape;
    landscape << QPoint(0, realHeight)
              << QPoint(20, realHeight - 20)
              << QPoint(40, realHeight - 15)
              << QPoint(60, realHeight - 22)
              << QPoint(80, realHeight - 44)
              << QPoint(100, realHeight - 69)
              << QPoint(120, realHeight - 100)
              << QPoint(140, realHeight - 105)
              << QPoint(160, realHeight - 95)
              << QPoint(180, realHeight - 73)
              << QPoint(200, realHeight - 53)
              << QPoint(220, realHeight - 31)
              << QPoint(240, realHeight - 16)
              << QPoint(260, realHeight - 13)
              << QPoint(280, realHeight - 17);

    scene->addPolygon(landscape, QPen(), QBrush(Qt::green));


    Cannon *blackCannon = new Cannon();
    blackCannon->setPosition(100, 100);
    scene->addItem(blackCannon->getPointer());
    blackCannon->setPosition(100, 250);

    //delete blackCannon
}


GameGUI::~GameGUI()
{
    delete scene;
    delete ui;
}
