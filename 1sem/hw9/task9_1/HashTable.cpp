#include "HashTable.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct HashTableCell
{
	int quantity = 0;
	String *key = nullptr;
	HashTableCell *next = nullptr;
};

struct HashTable
{
	int size = 0;
	int fullness = 0;
	HashTableCell **table = nullptr;
};


int hashFunction(String*, int);
HashTableCell* createCell(String*);
void updateTable(HashTable*);



int hashFunction(String *word, int divider)
{
	char *source = stringToChar(word);
	unsigned long long result = 0;
	for (int i = 0; i <= lengthOfString(word); i += 2)
	{
		result += source[i] * 14 + (result % 23);
	}
	for (int i = lengthOfString(word); i >= 0; i--)
	{
		result += source[i] * 17 + (result % 35);
	}
	result += divider / 19 * source[0];
	result %= divider;
	delete []source;
	return result;
}


HashTable* createTable()
{
	HashTable *newTable = new HashTable;
	const int size = 2048;  //  The starting value
	newTable->size = size;
	HashTableCell **cells = new HashTableCell*[size];
	for (int i = 0; i < size; i++)
	{
		cells[i] = nullptr;
	}
	newTable->table = cells;
	return newTable;
}


void addToHashTable(HashTable *thisTable, String *word)
{
	const int hashCode = hashFunction(word, thisTable->size);
	if (!isPresentInTable(thisTable, word))
	{
		thisTable->fullness++;
		HashTableCell *newCell = createCell(word);
		newCell->next = thisTable->table[hashCode];
		thisTable->table[hashCode] = newCell;
	}
	else
	{
		deleteString(word);
	}

	if (thisTable->fullness > 0.9 * thisTable->size)
	{
		updateTable(thisTable);
	}
}


HashTableCell* createCell(String *word)
{
	HashTableCell *cell = new HashTableCell;
	cell->quantity = 1;
	cell->key = word;
	return cell;
}


void updateTable(HashTable *thisTable)
{
	const int newSize = thisTable->size * 2;
	HashTableCell **newCells = new HashTableCell*[newSize];
	for (int i = 0; i < newSize; i++)
	{
		newCells[i] = nullptr;
	}

	HashTableCell *current = nullptr;
	HashTableCell *next = nullptr;
	int hashCode = 0;
	for (int i = 0; i < thisTable->size; i++)
	{
		current = thisTable->table[i];
		while (current)
		{
			next = current->next;
			hashCode = hashFunction(current->key, newSize);
			current->next = newCells[hashCode];
			newCells[hashCode] = current;
			current = next;
		}
	}
	delete []thisTable->table;
	thisTable->table = newCells;
	thisTable->size = newSize;
}


void deleteTable(HashTable *thisTable)
{
	HashTableCell *current = nullptr;
	HashTableCell *temp = nullptr;
	for (int i = 0; i < thisTable->size; i++)
	{
		current = thisTable->table[i];
		while (current)
		{
			deleteString(current->key);
			temp = current->next;
			delete current;
			current = temp;
		}
	}
	delete []thisTable->table;
	delete thisTable;
}


bool isPresentInTable(HashTable *thisTable, String *thisString)
{
	const int hashCode = hashFunction(thisString, thisTable->size);
	HashTableCell *current = thisTable->table[hashCode];
	while (current)
	{
		if (isTheSame(current->key, thisString))
		{
			return true;
		}
		current = current->next;
	}
	return false;
}