#include "arithmeticTree.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	cout << "This program calculates the value of the expression represented as a tree" << endl;
	cout << "Please be careful not to DIVIDE BY ZERO!" << endl;
	cout << "Please enter the name of input file" << endl;

	const int maxNameLength = 256;
	char theFileName[maxNameLength] = {};
	cin >> theFileName;

	FILE *userInputFile = fopen(theFileName, "r");
	if (userInputFile == nullptr)
	{
		cout << "Error: Cannot open file!" << endl;
		return 0;
	}

	cout << "Print the program's result to the console or to a file?" << endl;
	cout << "1 - console; 2 - file" << endl;

	int placePrint = 0;
	cin >> placePrint;
	if (placePrint == 2)
	{
		cout << "Please enter the name of your file for output data." << endl;
		cin >> theFileName;

		FILE *userOutputFile = freopen(theFileName, "w", stdout);
		calculateAndPrintTree(userInputFile);
		fclose(userOutputFile);
	}
	else if (placePrint == 1)
	{
		calculateAndPrintTree(userInputFile);
	}
	else
	{
		cout << "Error: It must only be 1 or 2!" << endl;
	}

	fclose(userInputFile);
	cout << endl;
	return 0;
}