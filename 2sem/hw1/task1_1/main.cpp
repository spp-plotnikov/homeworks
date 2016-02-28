#include <QCoreApplication>
#include <iostream>
#include "list.h"
#include "arraylist.h"
#include "pointerlist.h"

using namespace std;

void displayComments();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    displayComments();

    cout << "Select the method: 0 - array ";
    cout << "list, 1 - pointer list." << endl;
    List *list = NULL;
    int method = 0;
    cin >> method;

    enum methods {array, pointer};
    if (method == array)
        list = new ArrayList();
    else if (method == pointer)
        list = new PointerList();
    else
    {
        cout << "The method is not defined." << endl;
        return a.exec();
    }

    cout << "You can get started" << endl;
    int number = 0;
    enum typeOfCommands {exit, add, find, remove, print};
    int userCommand = 0;
    do
    {
        cin >> userCommand;
        switch (userCommand)
        {
        case add:
        {
            cout << "Please enter the new element" << endl;
            cin >> number;
            list->add(number);
            cout << "The new element was successfully added." << endl;
            break;
        }
        case find:
        {
            cout << "Please enter the targen element" << endl;
            cin >> number;
            if (list->isFound(number))
                cout << "is found" << endl;
            else
                cout << "is not found" << endl;
            break;
        }
        case remove:
        {
            cout << "Please enter the targen element" << endl;
            cin >> number;
            list->remove(number);
            cout << "You can continue" << endl;
            break;
        }
        case print:
        {
            cout << "Content of the list:" << endl;
            list->print();
            break;
        }
        default:
        {
            if (userCommand)
            {
                cout << "Error: Unknown command!" << endl;
            }
            break;
        }
        }
    } while (userCommand);
    delete list;
    return a.exec();
}


void displayComments()
{
    cout << "------------------------------------" << endl;
    cout << "This program is designed to work with the list." << endl;
    cout << "You can use following comands:" << endl;
    cout << "0 - exit" << endl;
    cout << "1 - add new element" << endl;
    cout << "2 - find the element" << endl;
    cout << "3 - remove the element" << endl;
    cout << "4 - print the list" << endl;
    cout << "------------------------------------" << endl;
}

