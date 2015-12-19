#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "sortedListLibrary.h"

using namespace std;

void displayComments();

int main()
{
    displayComments();
    List sortedList = createList();
    int userCommand = 0;
    do
    {
        cin >> userCommand;

        switch (userCommand)
        {
        case 1:
        {
            int newUserValue = 0;
            cout << "Please enter your value" << endl;
            cin >> newUserValue;
            addValueToSortedList(&sortedList, newUserValue);
            cout << "Now your value is in List" << endl;
            break;
        }
        case 2:
        {
            int forRemovalUserValue =0;
            cout << "Please enter value that you want to remove" << endl;
            cin >> forRemovalUserValue;
            removeValueFromSortedList(&sortedList, forRemovalUserValue);
            cout << "Now your value is removed from List" << endl;
            break;
        }
        case 3:
        {
            cout << "Your List: " << endl;
            printList(&sortedList);
            cout << endl;
            break;
        }
        default:
        {
            if (userCommand != 0)
            {
                cout << "Error: Unknown command!" << endl;
            }
            break;
        }
        }
    } while (userCommand != 0);

    removeList(&sortedList);
    return 0;
}

void displayComments()
{
    cout << "This app allows you to work with a sorted list" << endl;
    cout << "You can use the commands: " << endl;
    cout << "0 - exit;" << endl;
    cout << "1 - add a value to sorted list " << endl;
    cout << "2 - remove a value from sorted list " << endl;
    cout << "3 - print list." << endl;
    cout << "You can get started." << endl;
}
