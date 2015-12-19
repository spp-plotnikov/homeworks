#include "rabinKarp.h"
#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

unsigned long long calculateHashCode(char*, int);
bool isTheSame(char*, char*, int);

void rabinKarp(char *string, char *substring)
{
	const int stringLength = strlen(string);
	const int substringLength = strlen(substring);
	unsigned long long stringHash = calculateHashCode(string, substringLength);
	unsigned long long substringHash = calculateHashCode(substring, substringLength);
	const int base = 71;
	bool isFound = false;

	for (int i = 0; i < stringLength - substringLength + 1; i++)
	{
		if (stringHash == substringHash)
		{
			if (isTheSame(substring, string, i))
			{
				cout << "Position: " << i + 1 << endl;
				isFound = true;
			}
		}
		stringHash -= string[i] * unsigned long long(pow(base, substringLength - 1));
		stringHash = stringHash * base + string[substringLength + i];
	}
	if (!isFound)
	{
		cout << "No matches found!" << endl;
	}
}


unsigned long long calculateHashCode(char *string, int finalPosition)
{
	const int base = 71;
	unsigned long long hashCode = 0;

	for (int i = 0; i < finalPosition; i++)
	{
		hashCode += string[finalPosition - i - 1] * pow(base, i);
	}
	return hashCode;
}


bool isTheSame(char *substring, char *string, int position)  //  get rid of the collisions
{
	bool result = true;
	for (int i = 0; i < strlen(substring); i++)
	{
		if (substring[i] != string[position + i])
		{
			result = false;
		}
	}
	return result;
}