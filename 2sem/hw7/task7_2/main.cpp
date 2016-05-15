#include <QCoreApplication>
#include "vectortest.h"
#include "vector.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    VectorTest test;
    QTest::qExec(&test);

    return a.exec();
}
