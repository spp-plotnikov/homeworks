#include "circularListModule.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	cout << "This program is an implementation of the solution of Josephus problem" << endl;
	cout << "There are N soldiers. They kill every M'th" << endl;
	cout << "Please enter N and M" << endl;

	int amount = 0;
	cin >> amount;

	int regularity = 0;
	cin >> regularity;

	CircularList warriors = createCircularList(amount);
	cout << "Josephus Flavius takes the ";
	cout << findTheFlaviusJosephusPosition(&warriors, regularity);
	cout << " position." << endl;
	return 0;
}