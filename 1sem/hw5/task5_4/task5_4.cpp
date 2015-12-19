#include "phonebookDataBaseService.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

void displayComments();

int main()
{
	displayComments();

	const int maxNameLength = 256;
	char theFileName[maxNameLength] = {};
	const char defaultName[maxNameLength] = {"phonebook.database"};
	cin >> theFileName;
	if (theFileName[0] == 's' && theFileName[1] == '\0')
	{
		for (int i = 0; i < (int)strlen(defaultName); i++)
		{
			theFileName[i] = defaultName[i];
		}
	}

	cout << "You can get started" << endl;

	DataBase phonebook = createDataBase();
	int quantity = 0;
	scanTheDataBase(&phonebook, theFileName, quantity);

	const int maxLength = 1024;
	long long number;
	char name[maxLength] = {};

	enum typeOfCommands {exit, add, findPhone, findName, save};
	int userCommand = 0;
	do
	{
		cin >> userCommand;
		switch (userCommand)
		{
		case add:
		{
			cout << "Please enter the phone number and the name" << endl;
			cin >> number >> name;
			quantity++;
			addNewEntry(&phonebook, number, name);
			cout << "The entry was successfully added." << endl;
			break;
		}
		case findPhone:
		{
			cout << "Please enter the name" << endl;
			cin >> name;
			findEntry(&phonebook, -1, name);
			break;
		}
		case findName:
		{
			cout << "Please enter the phone" << endl;
			cin >> number;
			findEntry(&phonebook, number, "-1");
			break;
		}
		case save:
		{
			saveDataBase(&phonebook, theFileName, quantity);
			cout << "Successfully saved!" << endl;
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

	removeDataBase(phonebook);
	return 0;
}


void displayComments()
{
	cout << "------------------------------------" << endl;
	cout << "This program is phonebook" << endl;
	cout << "You can use following comands:" << endl;
	cout << "0 - exit" << endl;
	cout << "1 - add an entry (phone and name)" << endl;
	cout << "2 - find phone by name" << endl;
	cout << "3 - find name by phone" << endl;
	cout << "4 - save the current data to a file" << endl;
	cout << "------------------------------------" << endl;
	cout << "Enter \"s\" if you want to use a standard phone book.";
	cout << " Otherwise, enter the file name." << endl;
}
