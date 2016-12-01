#include <iostream>
#include "bubblesortertest.h"
#include "comparatortest.h"

int main()
{
    ComparatorTest comparatorTest;
    QTest::qExec(&comparatorTest);

    SorterTest sorterTest;
    QTest::qExec(&sorterTest);

    return 0;
}
