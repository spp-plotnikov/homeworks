#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

void printTheElements(int *arrayOfDigits[], int, int);

int main()
{
	cout << "This app displays the numbers from the array of size NxN ";
	cout << "in a spiral starting from the centre. N must be odd." << endl;
	cout << "Please enter N" << endl;

	int size = 0;
	cin >> size;

	int **arrayOfDigits;
	arrayOfDigits = new int*[size];
	for (int i = 0; i < size; i++)
	{
		arrayOfDigits[i] = new int[size];
	}
	
	cout << "The original array:" << endl;
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arrayOfDigits[i][j] = (rand() % 10);
			cout << arrayOfDigits[i][j] << ' ';
		}
		cout << endl;
	}

	cout << "Bypass on spiral: " << endl;
	const int centre = size / 2;
	cout << arrayOfDigits[centre][centre] << ' ';
	if (centre > 0)
	{
		printTheElements(arrayOfDigits, centre - 1, 2);
	}

	for (int i = 0; i < size; i++)
	{
		delete []arrayOfDigits[i];
	}
	delete []arrayOfDigits;

	return 0;
}

void printTheElements(int  *arrayOfDigits[], int start, int length)
{
	if (start >= 0)
	{
		for (int i = 1; i <= length; i++)
		{
			cout << arrayOfDigits[start][start + i] << ' ';
		}
		for (int i = 1; i <= length; i++)
		{
			cout << arrayOfDigits[start + i][start + length] << ' ';
		}
		for (int i = 1; i <= length; i++)
		{
			cout << arrayOfDigits[start + length][start + length - i] << ' ';
		}
		for (int i = 1; i <= length; i++)
		{
			cout << arrayOfDigits[start + length - i][start] << ' ';
		}
		printTheElements(arrayOfDigits, start - 1, length + 2);
	}
}