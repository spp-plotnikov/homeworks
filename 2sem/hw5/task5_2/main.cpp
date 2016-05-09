#include <QCoreApplication>
#include <iostream>
#include "avltreetest.h"
#include "settest.h"
#include "set.h"

using namespace std;

void showComments();
Set<int>* inviteUserToCreateNewSet();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    AVLTreeTest testAVLTree;
    QTest::qExec(&testAVLTree);

    SetTest setTest;
    QTest::qExec(&setTest);

    showComments();

    Set<int> *set = new Set<int>();
    enum Commands {exit, add, remove, find, showContent, setIntersection, setUnion};
    int command = 0;
    int value = 0;
    do
    {
        cin >> command;
        switch (command)
        {
        case add:
        {
            cout << "Please enter the value" << endl;
            cin >> value;
            set->add(value);
            cout << "This value was successfully added." << endl;
            break;
        }
        case remove:
        {
            cout << "Please enter your value" << endl;
            cin >> value;
            if (set->remove(value))
            {
                cout << "The value was successfully removed." << endl;
            }
            else
            {
                cout << "The set does not contain this element." << endl;
            }

            break;
        }
        case find:
        {
            cout << "Please enter your value" << endl;
            cin >> value;
            if (set->find(value))
            {
                cout << "The set contains this element." << endl;
            }
            else
            {
                cout << "The set does not contain this element." << endl;
            }
            break;
        }
        case showContent:
        {
            int quantity = 0;
            int *array = set->getContent(quantity);

            cout << "The content of the set: " << endl;
            for (int i = 0; i < quantity; i++)
            {
                cout << array[i] << " ";
            }
            cout << endl << "You can continue..." << endl;
            delete []array;
            break;
        }
        case setIntersection:
        {
            Set<int> *otherSet = inviteUserToCreateNewSet();
            set->setIntersection(*otherSet);
            delete otherSet;
            cout << "Done! Continue...." << endl;
            break;
        }
        case setUnion:
        {
            Set<int> *otherSet = inviteUserToCreateNewSet();
            set->setUnion(*otherSet);
            delete otherSet;
            cout << "Done! Continue...." << endl;
            break;
        }
        default:
        {
            if (command)
            {
                cout << "Error: Unknown command!" << endl;
            }
            break;
        }
        }
    } while (command);

    return a.exec();
}


void showComments()
{
    cout << "This app to work with the set." << endl;
    cout << "You can use following commands: " << endl;
    cout << "0 - exit" << endl;
    cout << "1 - add new value to the set" << endl;
    cout << "2 - remove the value from the set" << endl;
    cout << "3 - find the value in the set" << endl;
    cout << "4 - show content of the set" << endl;
    cout << "5 - intersect with other set" << endl;
    cout << "6 - merge with other set" << endl;
    cout << "You can start :)" << endl;
}


Set<int> *inviteUserToCreateNewSet()
{
    cout << "You should generate new set" << endl;
    cout << "Please enter the cardinality of the set" << endl;
    int cardinality = 0;
    cin >> cardinality;

    Set<int> *newSet = new Set<int>();
    int value = 0;
    for (int i = 0; i < cardinality; i++)
    {
        cout << "Please enter the value No" << i + 1 << ":" << endl;
        cin >> value;
        newSet->add(value);
    }
    return newSet;
}
