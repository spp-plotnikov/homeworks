#include "string.h"
#include "HashTable.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void scanFileAndPrintResults(FILE*, FILE*);

int main()
{
	cout << "This app looks for identical strings in";
	cout << " two files and outputs them in third." << endl;
	cout << "Please enter the name of your first file." << endl;

	const int maxNameLength = 256;
	char fileName[maxNameLength] = {};
	cin >> fileName;
	FILE *file1 = fopen(fileName, "rt");

	cout << "Please enter the name of your second file." << endl;
	cin >> fileName;
	FILE *file2 = fopen(fileName, "rt");

	cout << "Please enter the name of your third file." << endl;
	cin >> fileName;
	FILE *file3 = freopen(fileName, "w", stdout);

	scanFileAndPrintResults(file1, file2);
	fclose(file1);
	fclose(file2);
	fclose(file3);
	return 0;
}


void scanFileAndPrintResults(FILE *file1, FILE *file2)
{
	const int maxLength = 1024;
	char currentLine[maxLength] = {};
	String *line = nullptr;
	HashTable *table = createTable();
	while (!feof(file1))
	{
		fgets(currentLine, maxLength, file1);
		line = createString(currentLine);
		addToHashTable(table, line);
	}
	while (fgets(currentLine, maxLength, file2) != nullptr)
	{
		line = createString(currentLine);
		if (isPresentInTable(table, line))
		{
			printTheString(line);
		}
		deleteString(line);
	}
	deleteTable(table);
}
