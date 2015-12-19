#include "string.h"
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>

using namespace std;

void scanFileAndPrintResults(char*);
bool standardization(char*);

int main()
{
	cout << "This application counts the occurrences of each word." << endl;
	cout << "Please enter the name of your file." << endl;

	const int maxNameLength = 256;
	char theInputFileName[maxNameLength] = {};
	cin >> theInputFileName;
	FILE *userInputFile = fopen(theInputFileName, "rt");

	if (userInputFile == nullptr)
	{
		cout << "Error: Cannot open file!" << endl;
		return 0;
	}

	cout << "Print the program's result to the console or to a file?" << endl;
	cout << "0 - console; 1 - file" << endl;

	enum placesPrint {console, file};
	int placePrint = 0;
	cin >> placePrint;
	if (placePrint == file)
	{
		cout << "Please enter the name of your file for output data." << endl;
		char theOutputFileName[maxNameLength] = {};
		cin >> theOutputFileName;

		FILE *userOutputFile = freopen(theOutputFileName, "w", stdout);
		scanFileAndPrintResults(theInputFileName);
		fclose(userOutputFile);
	}
	else if (placePrint == console)
	{
		scanFileAndPrintResults(theInputFileName);
	}
	else
	{
		cout << "Error: It must only be 0 or 1!" << endl;
	}

	fclose(userInputFile);
	return 0;
}


void scanFileAndPrintResults(char *input)
{
	ifstream fin(input);
	char currentWord[70] = {}; //  Word length does not exceed 70
	String *word = nullptr;
	HashTable *table = createTable();
	while (!fin.eof())
	{
		fin >> currentWord;
		if (standardization(currentWord))
		{
			word = createString(currentWord);
			addToHashTable(table, word);
		}
	}
	printResults(table);
	deleteTable(table);
	fin.close();
}


bool standardization(char *word)
{
	int firstLetter = 0;
	const int length = strlen(word);
	while (firstLetter < length && !isalpha(word[firstLetter]))
	{
		firstLetter++;
	}
	if (firstLetter == length)
	{
		return false;    //  If it's not the word
	}
	for (int i = firstLetter; i < length; i++)
	{
		word[i - firstLetter] = word[i];
	}
	int lastLetter = length - firstLetter - 1;
	while (lastLetter > 0 && !isalpha(word[lastLetter]))
	{
		lastLetter--;
	}
	if (lastLetter < length && lastLetter >= 0)
	{
		word[lastLetter + 1] = '\0';
	}
	word[0] = tolower(word[0]);    //  In case if the first letter is uppercase
	return true;
}
