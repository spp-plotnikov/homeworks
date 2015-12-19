#include "HuffmanDecoding.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	cout << "This app decompresses the data." << endl;
	cout << "Please enter the name of your file." << endl;

	const int maxNameLength = 256;
	char theFileName[maxNameLength] = {};
	cin >> theFileName;

	FILE *userInputFile = fopen(theFileName, "r");
	if (userInputFile == nullptr)
	{
		cout << "Error: Cannot open file!" << endl;
		return 0;
	}

	cout << "Please enter the name of file for output data" << endl;
	cin >> theFileName;
	FILE *userOutputFile = fopen(theFileName, "w");

	decompressTheData(userInputFile, userOutputFile);
	cout << "Successfully done!" << endl;

	fclose(userOutputFile);
	fclose(userInputFile);
	return 0;
}