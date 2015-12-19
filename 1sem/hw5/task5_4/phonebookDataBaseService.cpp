#include "phonebookDataBaseService.h"
#include <fstream>
#include <iostream>
#include <string.h>


Entry* createNewElement(long long, char*);

void findEntry(DataBase *thisDataBase, long long thisNumber, const char *thisName)
{
	long long fieldOfEntry = thisNumber;
	Entry *current = thisDataBase->first;
	if (current != nullptr)
	{
		while (current != nullptr)
		{
			if (!strcmp(current->name, thisName))
			{
				thisNumber = current->number;
				break;
			}
			if (current->number == thisNumber)
			{
				thisName = current->name;
				break;
			}
			current = current->next;
		}
	}
	if (thisNumber == -1 || thisName == "-1")
	{
		cout << "This man was not found" << endl;

	}
	else
	{
		cout << "The entry was found: " << endl;
		if (fieldOfEntry == -1)
		{
			cout << "Number: " << thisNumber << endl;
		}
		else
		{
			cout << "Name: " << thisName << endl;
		}
	}
	cout << endl << "Please continue" << endl;
}


DataBase createDataBase()
{
	DataBase newDataBase = {nullptr};
	return newDataBase;
}


void addNewEntry(DataBase *thisDataBase, long long newNumber, char* newName)
{
	Entry *current = thisDataBase->first;
	if (current == nullptr)
	{
		thisDataBase->first = createNewElement(newNumber, newName);
	}
	else
	{
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = createNewElement(newNumber, newName);
	}
}


Entry* createNewElement(long long newNumber, char *newName)
{
	Entry *newElement = new Entry;
	newElement->number = newNumber;
	strcpy(newElement->name, newName);
	newElement->next = nullptr;

	return newElement;
}


void scanTheDataBase(DataBase *phonebook, char *theFileName, int &quantity)
{
	if (fopen(theFileName, "rt") == nullptr)
	{
		FILE *newFile = fopen(theFileName, "w");
		fprintf(newFile, "0");
		fclose(newFile);
	}

	ifstream fin(theFileName);

	fin >> quantity;
	const int maxLength = 1024;
	long long number;
	char name[maxLength] = {};

	for (int i = 1; i <= quantity; i++)
	{
		fin >> number >> name;
		addNewEntry(phonebook, number, name);
	}

	fin.close();
}


void saveDataBase(DataBase *thisDataBase, char *theFileName, int quantity)
{
	ofstream fout(theFileName);
	fout << quantity << endl;

	Entry *current = thisDataBase->first;
	if (current != nullptr)
	{
		while (current != nullptr)
		{
			fout << current->number << " " << current->name << endl;
			current = current->next;
		}
	}

	fout.close();
}


void removeDataBase(DataBase &thisDataBase)
{
	while (thisDataBase.first != nullptr)
	{
		Entry *temp = thisDataBase.first->next;
		delete thisDataBase.first;
		thisDataBase.first = temp;
	}
}