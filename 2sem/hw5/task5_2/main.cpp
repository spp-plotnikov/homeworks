#include <QCoreApplication>
#include "avltreetest.h"
#include "settest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AVLTreeTest testAVLTree;
    QTest::qExec(&testAVLTree);

    SetTest setTest;
    QTest::qExec(&setTest);

    return a.exec();
}
