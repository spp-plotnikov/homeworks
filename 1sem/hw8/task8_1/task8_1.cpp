#include "QueueServise.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void readDataAndPrintResult(char*);
void traversal(Queue*, char*, char*, int);

int main()
{
	cout << "This application enumerates the vertices ";
	cout << "of the graph using the letters of the Latin alphabet." << endl;
	cout << "PLEASE NOTE! IN THE LATIN ALPHABET ONLY 26 LETTERS!!!" << endl;
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
	}

	return 0;
}

void readDataAndPrintResult(char *theFileName)
{
	ifstream fin(theFileName);
	int quantity = 0;
	fin >> quantity;
	int edges = 0;
	fin >> edges;

	Queue *vertices = new Queue[quantity + 1];
	char *number = new char[quantity + 1];
	number[0] = 'a' - char(1);
	for (int i = 1; i <= quantity; i++)
	{
		number[i] = number[0];
	}
	int vertex1 = 0;
	int vertex2 = 0;
	for (int i = 1; i <= edges; i++)
	{
		fin >> vertex1 >> vertex2;
		pushBack(&vertices[vertex1], vertex2);
	}
	int start = 0;
	fin >> start;
	char k = number[0];
	traversal(vertices, number, &k, start);
	for (int i = 1; i <= quantity; i++)
	{
		cout << "Vertex" << i << ": " << number[i] << endl;
	}

	delete []number;
	delete []vertices;
	fin.close();
}


void traversal(Queue *vertices, char *number, char *k, int i)
{
	if (number[i] == number[0])
	{
		*k += char(1);
		number[i] = *k;
	}
	while (!isEmpty(&vertices[i]))
	{
		traversal(vertices, number, k, popFront(&vertices[i]));
	}
}