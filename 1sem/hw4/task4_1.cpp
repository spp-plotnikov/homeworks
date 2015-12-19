#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	cout << "This application checks the possibility of obtaining from the first string ";
	cout << "to a second by permutation of the symbols" << endl;
	cout << "Please enter first string and press Enter" << endl;

	const int maxLength = 260;
	char firstString[maxLength] = {};
	cin.getline(firstString, maxLength);

	cout << "Please enter second string and press Enter" << endl;

	char secondString[maxLength] = {};
	cin.getline(secondString, maxLength);

	const int maxValueOfChar = 256;
	const int  shiftToPositive = 127; //type char takes the values from -127 to 127
	int counterOfFirstStringSymbols[maxValueOfChar] = {};
	int counterOfSecondStringSymbols[maxValueOfChar] = {};

	bool isTheSame = (strlen(firstString) == strlen(secondString));
	if (isTheSame)
	{
		for (int i = 0; i < strlen(firstString); i++)
		{
			counterOfFirstStringSymbols[firstString[i] + shiftToPositive]++;
			counterOfSecondStringSymbols[secondString[i] + shiftToPositive]++;
		}

		for (int i = 0; i < maxValueOfChar; i++)
		{
			if (counterOfFirstStringSymbols[i] != counterOfSecondStringSymbols[i])
			{
				isTheSame = false;
				break;
			}
		}
	}

	if (isTheSame)
	{
		cout << "Possible" << endl;
	}
	else
	{
		cout << "Impossible" << endl;
	}
	
	return 0;
}