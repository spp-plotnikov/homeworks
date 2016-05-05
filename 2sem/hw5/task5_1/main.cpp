#include <QCoreApplication>
#include "arithmetictreetest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ArithmeticTreeTest test;
    QTest::qExec(&test);

    return a.exec();
}
