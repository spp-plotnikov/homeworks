#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int traversal(int*, int*, int);

int main()
{
	cout << "Enter the number of students: " << endl;

	int quantity = 0;
	cin >> quantity;

	cout << "Enter the pairs of numbers: student number";
	cout << " and number of someone who gave written off decision." << endl;
	cout << "To end input, enter 0 0" << endl;

	int *adjacencyList = new int[quantity +1];
	int *result = new int[quantity + 1];
	for (int i = 1; i <= 3; i++)
	{
		result[i] = i;
	}
	for (int i = 4; i <= quantity; i++)
	{
		result[i] = 0;
		adjacencyList[i] = 0;
	}

	int number = 0;
	do
	{
		cin >> number;
		cin >> adjacencyList[number];
	} while (number != 0);

	for (int i = 4; i <= quantity; i++)
	{
		traversal(adjacencyList, result, i);
	}

	cout << "The result of the execution of the application: " << endl;
	for (int i = 1; i <= quantity; i++)
	{
		cout << i << ": ";
		if (result[i] == 0)
		{
			cout << "expelled" << endl;
		}
		else if (result[i] < i)
		{
			cout << result[i] << endl;
		}
		else
		{
			cout << "did it himself" << endl;
		}
	}

	delete []result;
	delete []adjacencyList;
	return 0;
}


int traversal(int adjacencyList[], int result[], int current)
{
	if (current <= 3)
	{
		return current;
	}
	else
	{
		if (result[current] == 0)
		{
			int temp = traversal(adjacencyList, result, adjacencyList[current]);
			result[current] = temp;
			return temp;
		}
		else
		{
			return result[current];
		}
	}
}
