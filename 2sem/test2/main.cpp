#include <QCoreApplication>
#include <iostream>
#include "comparator.h"
#include "bubblesorter.h"
#include "intsinabsolutevaluecomparator.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    list.append(-77);
    list.append(-3);
    list.append(5632);
    list.append(3);
    list.append(7);
    list.append(1);
    Comparator<int> *comparator = new IntsInAbsoluteValueComparator<int>();
    BubbleSorter<int>::sort(list, *comparator);
    for (int i = 0; i < list.size(); i++)
    {
        std::cout << list[i] << ' ';
    }

    delete comparator;
    return a.exec();
}
