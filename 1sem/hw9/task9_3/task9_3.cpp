#include "prim.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	cout << "There is the undirected weighted graph with N vertices and M edges. ";
	cout << "This app builds a minimum spanning tree of a weighted ";
	cout << "connected undirected graph by using of Prim's algorithm." << endl;
	cout << "Please enter the name of your file." << endl;

	const int maxNameLength = 256;
	char theFileName[maxNameLength] = {};
	cin >> theFileName;
	
	FILE *userInputFile = fopen(theFileName, "rt");

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
		char theOutputFileName[maxNameLength] = {};
		cin >> theOutputFileName;

		FILE *userOutputFile = freopen(theOutputFileName, "w", stdout);
		readDataAndPrintResult(theFileName);
		fclose(userOutputFile);

	}
	else if (placePrint == 1)
	{
		readDataAndPrintResult(theFileName);
	}
	else
	{
		cout << "Error: It must only be 1 or 2!" << endl;
	}
	fclose(userInputFile);

	return 0;
}