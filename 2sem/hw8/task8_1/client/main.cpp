#include "clientspp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientSPP w;
    w.show();

    return a.exec();
}
