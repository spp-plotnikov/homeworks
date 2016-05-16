#include <QCoreApplication>
#include <QtTest/QtTest>
#include <iostream>
#include "list.h"
#include "avltree.h"
#include "arraylist.h"
#include "sortedset.h"
#include "pointerlist.h"
#include "sortedsettest.h"
#include "comparatortest.h"



using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ComparatorTest comparatorTest;
    QTest::qExec(&comparatorTest);

    SortedSetTest sortedSetTest;
    QTest::qExec(&sortedSetTest);

    SortedSet<List> *set = new SortedSet<List>();

    cout << "Enter the number of lists that you want to add to SortedSet. " << endl;
    int quantityOfLists = 0;
    cin >> quantityOfLists;
    List **lists = new List*[quantityOfLists];

    cout << "Fill each list, please. " << endl;
    enum Methods {array, pointer};
    for (int i = 0; i < quantityOfLists; i++)
    {
        cout << endl << "Enter the number of elements in the list No" << i + 1 << endl;
        int size = 0;
        cin >> size;

        cout << "Select the method: 0 - array ";
        cout << "list, 1 - pointer list." << endl;
        int method = 0;
        cin >> method;

        if (method == array)
            lists[i] = new ArrayList();
        else if (method == pointer)
            lists[i] = new PointerList();
        else
        {
            cout << "The method is not defined." << endl;
            break;
        }

        cout << "Enter the " << size << " elements of this list. " << endl;
        int newElement = 0;
        for (int j = 0; j < size; j++)
        {
            cin >> newElement;
            lists[i]->add(newElement);
        }

        cout << "OK, this list is full. You can continue... " << endl;
        try
        {
            set->add(lists[i]);
        }
        catch (SortedSet<List>::ElementExistsException &)
        {
            cout << "Error: You can't add this list, because it already exists" << endl;
            cout << "Please continue..." << endl;
        }
    }

    cout << "Well done! Maybe you want to see the contents of the SortedSet: " << endl << " ";
    set->displayContent();

    delete set;
    for (int i = 0; i < quantityOfLists; i++)
    {
        delete lists[i];
    }
    delete []lists;
    return a.exec();
}
