#include <QCoreApplication>
#include "sharedpointertest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SharedPointerTest test;
    QTest::qExec(&test);

    return a.exec();
}
