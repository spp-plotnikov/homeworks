#include "parser.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	cout << "This application is the parser of arithmetic expressions." << endl;
	cout << "Please enter the expression.";
	cout << " You can use numbers of any type";
	cout << " (float, int) and operation signs: +, -, /, *" << endl;

	const int maxLen = 1024;
	char expression[maxLen] = {};
	cin.getline(expression, maxLen - 1);
	if (isCorrectExpression(expression))
	{
		cout << "Your expression is correct!" << endl;
	}
	else
	{
		cout << "Your expression is not correct!" << endl;
	}
	return 0;
}