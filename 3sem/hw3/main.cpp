#include "gamegui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameGUI w;
    w.show();

    return a.exec();
}
