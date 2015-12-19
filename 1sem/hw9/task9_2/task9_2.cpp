#include "rabinKarp.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	cout << "This app searches for a substring in ";
	cout << "a string, using the Rabin-Karp algorithm" << endl;

	cout << "Please enter the string" << endl;
	const int maxLength = 2048;
	char string[maxLength] = {};
	cin.getline(string, maxLength);

	cout << "Please enter the substring" << endl;
	char substring[maxLength] = {};
	cin.getline(substring, maxLength);

	rabinKarp(string, substring);
	return 0;
}