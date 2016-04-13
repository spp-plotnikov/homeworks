#include <QCoreApplication>
#include <iostream>
#include "hashtable.h"

void showComments();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    showComments();
    enum Commands {exit, add, remove, find, statistics, changeFunction};
    int command = 0;
    QString currentString;

    HashTable<QString> *table = new HashTable<QString>(ololo);
    do
    {
        cin >> command;
        switch (command)
        {
        case add:
        {
            cout << "Please enter the string" << endl;
            cin >> currentString;
            table->add(currentString);
            cout << "The string was successfully added." << endl;
            break;
        }
        case remove:
        {
            cout << "Please enter the string" << endl;
            cin >> currentString;
            if (table->remove(currentString))
            {
                cout << "The string was successfully removed." << endl;
            }
            else
            {
                cout << "The table does not contain this element." << endl;
            }

            break;
        }
        case find:
        {
            cout << "Please enter the string" << endl;
            cin >> currentString;
            if (table->find(currentString))
            {
                cout << "The table contains this element." << endl;
            }
            else
            {
                cout << "The table does not contain this element." << endl;
            }
            break;
        }
        case statistics:
        {
            table->statistics();
            break;
        }
        case changeFunction:
        {
            int number = 0;
            cout << "Please enter the number of hash function (1 or 2)" << endl;
            cin >> number;
            if (number == 1)
            {
                table->setHashFunction(ololo1);
            }
            else if (number == 2)
            {
                table->setHashFunction(ololo2);
            }
            else
            {
                cout << "Error: Wrong number" << endl;
            }
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

    delete table;
    return a.exec();
}


void showComments()
{
    cout << "This app to work with the hash table." << endl;
    cout << "You can use following commands: " << endl;
    cout << "0 - exit" << endl;
    cout << "1 - add new value (string) to the hash table" << endl;
    cout << "2 - remove the value from the hash table" << endl;
    cout << "3 - find the value in the hash table" << endl;
    cout << "4 - show statistics on the hash table" << endl;
    cout << "5 - change the established hash function to ";
    cout << "another with certain number" << endl << "You can ";
    cout << "use numbers 1 and 2. The default is number 1." << endl;
    cout << "You can start :)" << endl;
}
