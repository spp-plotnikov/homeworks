#include <iostream>
#include "bagtest.h"
#include "avltreetest.h"

int main()
{
    AVLTreeTest avltreeTest;
    QTest::qExec(&avltreeTest);

    BagTest bagTest;
    QTest::qExec(&bagTest);

    return 0;
}
