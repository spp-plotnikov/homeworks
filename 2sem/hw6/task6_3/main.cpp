#include <QCoreApplication>
#include "../../../2sem/hw1/task1_1/pointerlist.h"
#include "../../../2sem/hw5/task5_2/set.h"
#include "sharedpointertest.h"
#include "sharedpointer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SharedPointerTest test;
    QTest::qExec(&test);

    //  Examples of usage of the pointer (according to the task)

    //  Example 1:
    SharedPointer<PointerList> list(new PointerList());
    list->add(1);
    list->remove(1);    //  it will be correct

    //  Example 2:
    SharedPointer<Set<int>> intSet1(new Set<int>());
    SharedPointer<Set<int>> intSet2(nullptr);

    int value = 43;
    intSet1->add(value);
    intSet2 = intSet1;
    intSet2->find(value);  //  it will be true


    return a.exec();
}
