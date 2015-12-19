#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

void displayComments(FILE*);

int main()
{
	cout << "This program displays single-line comments from the input file" << endl;
	cout << "Please enter the name of file" << endl;

	const int maxNameLength = 256;
	char theFileName[maxNameLength] = {};
	cin >> theFileName;

	FILE *userInputFile = fopen(theFileName, "rt");
	if (userInputFile == nullptr)
	{
		cout << "Error: Cannot open file!";
	}
	else
	{
		cout << "Comments";
		displayComments(userInputFile);
		fclose(userInputFile);
	}

	cout << endl;
	return 0;
}

void displayComments(FILE* userInputFile)
{
	char currentChar = '\0';
	char previousChar = '\0';
	bool isComment = false;
	bool isBigComment = false;
	bool isQuotes = false;

	while (!feof(userInputFile))
	{
		previousChar = currentChar;
		currentChar = fgetc(userInputFile);

		switch (currentChar)
		{
		case '/':
		{
			if (previousChar == '*')
			{
				isBigComment = false;
			}
			else if (previousChar == '/')
			{
				isComment = true;
				if (!isBigComment && !isQuotes)
				{
					cout << endl << "//";
				}
			}
			break;
		}
		case '*':
		{
			if (previousChar == '/')
			{
				isBigComment = true;
			}
			break;
		}
		case '"':
		{
			isQuotes = !isQuotes;
			break;
		}
		case '\0':
		case '\n':
		{
			isComment = false;
		}
		default:
		{
			if (isComment && !isBigComment && !isQuotes)
			{
				cout << currentChar;
			}
			break;
		}
		}
	}
}