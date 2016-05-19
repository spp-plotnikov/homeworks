#include "bashquotes.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BashQuotes w;
    w.setFixedSize(414, 320);
    w.show();

    return a.exec();
}
