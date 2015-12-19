#include "dijkstra.h"
#include <iostream>
#include <fstream>
#include <climits>

void dijkstra(int**, int*, int*, int*, int);
void printRoute(int*, int);

using namespace std;

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
			matrix[i][j] = 0;
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
	int *routes = new int[vertices];
	int *distances = new int[vertices];
	int *order = new int[vertices];
	dijkstra(matrix, routes, distances, order, vertices);

	cout << "Cities listed in the order of capture:" << endl;
	for (int i = 1; i < vertices; i++)
	{
		cout << "City No" << order[i] << ": ";
		cout << "distance - " << distances[order[i]] << "; ";
		cout << "route: ";
		printRoute(routes, order[i]);
		cout << endl;
	}

	delete[]order;
	delete[]routes;
	delete[]distances;
	for (int i = 0; i < vertices; i++)
	{
		delete[]matrix[i];
	}
	delete[]matrix;

	fin.close();
}


void dijkstra(int **matrix, int *routes, int *distances, int *order, int vertices)
{
	bool *visited = new bool[vertices];
	for (int i = 0; i < vertices; i++)
	{
		distances[i] = INT_MAX;
		visited[i] = false;
	}
	distances[1] = 0;
	routes[1] = 0;

	for (int k = 1; k < vertices; k++)
	{
		int min = INT_MAX;
		int index = 0;
		for (int i = 1; i < vertices; i++)
		{
			if (!visited[i] && distances[i] <= min)
			{
				min = distances[i];
				index = i;
			}
		}
		visited[index] = true;
		order[k] = index;
		for (int i = 1; i < vertices; i++)
		{
			if (!visited[i] && matrix[index][i] && distances[index] != INT_MAX &&
				distances[index] + matrix[index][i] < distances[i])
			{
				distances[i] = distances[index] + matrix[index][i];
				routes[i] = index;
			}
		}
	}
	delete[]visited;
}


void printRoute(int *routes, int index)
{
	if (index != 0)
	{
		printRoute(routes, routes[index]);
		cout << index << ' ';
	}
}
