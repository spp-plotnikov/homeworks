#include "QueueServise.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void traversal(Queue*, int*, int, int);
void printTheResult(int*, int, int);

int main()
{
	cout << "This application searches connected components in the graph." << endl;
	cout << "Enter the number of vertices" << endl;

	int quantity = 0;
	cin >> quantity;
	Queue *vertices = new Queue[quantity + 1];
	int *component = new int[quantity + 1];
	for (int i = 1; i <= quantity; i++)
	{
		component[i] = 0;
	}

	cout << "Enter the edges of the graph in format: Vertex1 Vertex2" << endl;
	cout << "Numbering starts at 1" << endl;
	cout << "To end input, enter 0 0" << endl;

	int vertex1 = 0;
	int vertex2 = 0;
	do
	{
		cin >> vertex1 >> vertex2;
		pushBack(&vertices[vertex1], vertex2);
		pushBack(&vertices[vertex2], vertex1);
	} while (vertex1 != 0);

	int k = 0;
	for (int i = 1; i <= quantity; i++)
	{
		if (component[i] == 0)
		{
			k++;
			traversal(vertices, component, i, k);
		}
	}
	printTheResult(component, quantity, k);

	delete []vertices;
	delete []component;
	return 0;
}

void traversal(Queue *vertices, int *component, int i, int k)
{
	component[i] = k;
	while (!isEmpty(&vertices[i]))
	{
		traversal(vertices, component, popFront(&vertices[i]), k);
	}
}

void printTheResult(int *component, int quantity, int quantityOfComponents)
{
	Queue *inSameComponent = new Queue[quantityOfComponents + 1];
	for (int i = 1; i <= quantity; i++)
	{
		pushBack(&inSameComponent[component[i]], i);
	}
	for (int i = 1; i <= quantityOfComponents; i++)
	{
		cout << "Connected component No." << i << ": ";
		while (!isEmpty(&inSameComponent[i]))
		{
			cout << popFront(&inSameComponent[i]) << ' ';
		}
		cout << endl;
	}
	delete []inSameComponent;
}