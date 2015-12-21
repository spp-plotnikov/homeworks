#include "analyzer.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	cout << "This application checks for the correctness";
	cout << " of the entry of your floating point number." << endl;
	cout << "Please enter your floating point number" << endl;

	const int maxLen = 256;
	char string[maxLen] = {};
	cin >> string;

	if (isCorrectFloat(string))
	{
		cout << "Your floating point number is correct!" << endl;
	}
	else
	{
		cout << "Your floating point number is not correct!" << endl;
	}
	return 0;
}
