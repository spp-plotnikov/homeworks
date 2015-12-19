#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>

using namespace std;

void printWordsFromFile(FILE*);

int main()
{
	cout << "This program prints words from file and removes same characters." << endl;
	cout << "Please enter the name of your file." << endl;
	
	const int maxNameLength = 256;
	char theFileName[maxNameLength] = {};
	cin >> theFileName;

	FILE *userInputFile = fopen(theFileName, "rt");

	if (userInputFile == nullptr)
	{
		cout << "Error: Cannot open file!" << endl;
	}
	else
	{
		cout << "Print the program's result to the console or to a file?" << endl;
		cout << "1 - console; 2 - file" << endl;

		int placePrint = 0;
		cin >> placePrint;
		if (placePrint == 2)
		{
			cout << "Please enter the name of your file for output data." << endl;
			cin >> theFileName;

			FILE *userOutputFile = freopen(theFileName, "w", stdout);
			printWordsFromFile(userInputFile);
			fclose(userOutputFile);

		}
		else if (placePrint == 1)
		{
			printWordsFromFile(userInputFile);
		}
		else
		{
			cout << "Error: It must only be 1 or 2!" << endl;
		}

		fclose(userInputFile);
	}

	return 0;
}

void printWordsFromFile(FILE *userInputFile)
{
	const int alphobetSize = int('z') - int('a') + 1;
	const int shift = int('a') - int('A');
	const int maxLength = 1024;

	char newWord[alphobetSize + 1] = {};
	char currentLine[maxLength] = {};
	bool wasUsed[CHAR_MAX + 1];

	for (int i = 0; i < CHAR_MAX; i++)
	{
		wasUsed[i] = false;
	}

	while (!feof(userInputFile))
	{
		fgets(currentLine, maxLength, userInputFile);
		for (int i = 0; i < strlen(currentLine); i++)
		{
			if (currentLine[i] >= int('a') && currentLine[i] <= int('z') && !wasUsed[currentLine[i]])
			{
				wasUsed[currentLine[i]] = true;
				newWord[strlen(newWord)] = currentLine[i];
				cout << currentLine[i];
			}
			else if (currentLine[i] < int('a') || currentLine[i] > int('z'))
			{
				cout << currentLine[i];
			}

			if (currentLine[i] == ' ' || currentLine[i] == '\0' || currentLine[i] == '\n')
			{
				for (int j = strlen(newWord) - 1; j >= 0; j--)
				{
					wasUsed[newWord[j]] = false;
					newWord[j] = '\0';
				}
			}

			if (currentLine[i] >= int('A') && currentLine[i] <= int('Z'))
			{

				wasUsed[currentLine[i] + shift] = true;
				newWord[strlen(newWord)] = currentLine[i] + shift;
			}
		}
	}

}