#include "prim.h"
#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

void prim(int**, int);

void readDataAndPrintResult(char *theFileName)
{
	ifstream fin(theFileName);
	int vertices = 0;
	fin >> vertices;
	int edges = 0;
	fin >> edges;

	vertices++;
	int **matrix = new int*[vertices];
	for (int i = 0; i < vertices; i++)
	{
		matrix[i] = new int[vertices];
	}
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			matrix[i][j] = INT_MAX;
		}
	}

	int vertex1 = 0;
	int vertex2 = 0;
	int weight = 0;
	for (int i = 1; i <= edges; i++)
	{
		fin >> vertex1 >> vertex2 >> weight;
		matrix[vertex1][vertex2] = weight;
		matrix[vertex2][vertex1] = weight;
	}

	cout << "Minimum spanning tree of a weighted connected undirected graph: " << endl;
	prim(matrix, vertices);

	for (int i = 0; i < vertices; i++)
	{
		delete []matrix[i];
	}
	delete []matrix;
	fin.close();
}


void prim(int **matrix, int quantity)
{
	bool *visited = new bool[quantity];
	for (int i = 0; i < quantity; i++)
	{
		visited[i] = false;
	}
	visited[1] = true;

	int k = 1;
	int minWeight = 0;
	int min = INT_MAX;
	int vertex1 = 0;
	int vertex2 = 0;
	while (k < quantity - 1)
	{
		min = INT_MAX;
		for (int i = 1; i < quantity; i++)
		{
			for (int j = 1; j < quantity; j++)
			{
				if (matrix[i][j] < min && visited[i])
				{
					min = matrix[i][j];
					vertex1 = i;
					vertex2 = j;
				}
			}
		}


		if (!visited[vertex1] || !visited[vertex2])
		{
			cout << k++ << ") " << vertex1 << " " << vertex2;
			cout << " weight: " << min << endl;
			minWeight += min;
			visited[vertex2] = true;

		}
		matrix[vertex1][vertex2] = INT_MAX;
		matrix[vertex2][vertex1] = INT_MAX;
	}
	cout << "Minimum weight: " << minWeight << endl;
	delete []visited;
}
