#include "plotnikovHeapSort.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;


int main()
{
	cout << "This application seeks the maximum element of the array, which occurs more than once" << endl;
	cout << "Please enter quantity of elements" << endl;

	int quantity = 0;
	cin >> quantity;

	cout << "Please enter " << quantity << " elements of array and press Enter" << endl;

	int *elements = new int[quantity];
	for (int i = 0; i < quantity; i++)
	{
		elements[i] = 0;
	}
	for (int i = 0; i < quantity; i++)
	{
		cin >> elements[i];
	}

	heapSortFunction(elements, quantity);

	bool isFound = false;
	for (int i = quantity; i > 0; i--)
	{
		if (elements[i] == elements[i - 1])
		{
			cout << "The element that matches the criteria is found: " << elements[i] << endl;
			isFound = true;
			break;
		}
	}
	if (!isFound)
	{
		cout << "The element that matches the criteria is not found!" << endl;
	}

	delete []elements;
	return 0;
}