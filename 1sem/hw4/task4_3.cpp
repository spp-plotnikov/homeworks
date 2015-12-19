#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	cout << "This program rearranges the digits of natural number ";
	cout << "in such a way as to form the smallest number ";
	cout << "recorded by the same digits." << endl;
	cout << "Please enter N" << endl;

	unsigned long long number = 0;
	cin >> number;

	const int decimal = 10;
	int digits[decimal] = {};
	while (number != 0)
	{
		digits[number % decimal]++;
		number /= decimal;
	}

	for (int i = 1; i < decimal; i++)
	{
		if (digits[i] != 0)
		{
			number = i;
			digits[i]--;
			break;
		}
	}
	for (int i = 0; i < decimal; i++)
	{
		for (int j = 1; j <= digits[i]; j++)
		{
			number *= decimal;
			number += i;
		}
	}

	cout << "Result: " << number << endl;
	return 0;
}