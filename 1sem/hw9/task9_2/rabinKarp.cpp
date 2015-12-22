#include "rabinKarp.h"
#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

unsigned long long calculateHashCode(char*, int);
bool isTheSame(char*, char*, int);
unsigned long long power(int, int);

void rabinKarp(char *string, char *substring)
{
	const int stringLength = strlen(string);
	const int substringLength = strlen(substring);
	long long stringHash = calculateHashCode(string, substringLength);
	unsigned long long substringHash = calculateHashCode(substring, substringLength);
	const unsigned long long module = 1000000007;
	const int base = 113;
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
		stringHash -= (string[i] * power(base, substringLength - 1) % module);
		if (stringHash < 0)
			stringHash += module;
		stringHash = stringHash * base + string[substringLength + i];
		stringHash %= module;
	}
	if (!isFound)
	{
		cout << "No matches found!" << endl;
	}
}


unsigned long long calculateHashCode(char *string, int finalPosition)
{
	const int base = 113;
	unsigned long long hashCode = 0;
	const unsigned long long module = 1000000007;

	for (int i = 0; i < finalPosition; i++)
	{
		hashCode += string[finalPosition - i - 1] * power(base, i);
		hashCode %= module;
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


unsigned long long power(int base, int exponent)
{
	unsigned long long result = 1;
	const unsigned long long module = 1000000007;
	for (int i = 1; i <= exponent; i++)
	{
		result *= base;
		result %= module;
	}
	return result;
}