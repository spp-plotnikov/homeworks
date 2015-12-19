#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "This program represents the double number in exponential form" << endl;
	cout << "Please enter the number" << endl;

	double value = 0;
	cin >> value;
	
	double duplicateValue = value;

	unsigned long long *data = (unsigned long long*)&value;
	double mantissa = 1;
	long long multiplier = 4503599627370496; //This is 2^52
	for (int i = 1; i <= 52; i++)
	{
		mantissa += (*data & 1) * (1.0 / multiplier);
		multiplier /= 2;
		*data >>= 1;
		
	}

	int exponent = 0;
	multiplier = 1;
	for (int i = 1; i <= 11; i++)
	{
		exponent += (*data & 1) * multiplier;
		multiplier *= 2;
		*data >>= 1;

	}
	exponent -= 1023;

	if (duplicateValue == 0)
	{
		exponent = 0;
		mantissa = 0;
	}

	*data ? cout <<  "-" : cout <<  "+";
	cout << setprecision(20) << mantissa << "*2^(" << exponent << ")" << endl;

	return 0;
}