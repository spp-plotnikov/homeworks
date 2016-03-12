#include <QCoreApplication>
#include <iostream>
#include "list.h"
#include "arraylist.h"
#include "pointerlist.h"
#include "listscomparator.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    List *x = new PointerList();
//    List *y = new ArrayList();

//    cout << ListsComparator::compare(x, y) << " ";
//    x->add(7);
//    cout << ListsComparator::compare(x, y) << " ";
//    x->add(8);
//    cout << ListsComparator::compare(x, y) << " ";
//    y->add(9);
//    cout << ListsComparator::compare(x, y) << " ";
//    y->add(10);
//    cout << ListsComparator::compare(x, y) << " ";
//    y->add(7);
//    cout << ListsComparator::compare(x, y) << " ";
    return a.exec();
}

