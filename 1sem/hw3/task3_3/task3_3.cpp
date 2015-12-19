#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "calculatePostfixExpression.h"

using namespace std;

int main()
{
	cout << "This application evaluates the expression represented in postfix form." << endl;
	cout << "Please enter your expression" << endl;
	
	const int maxLength = 260;
	char postfixForm[maxLength] = {};
	cin.getline(postfixForm, maxLength);

	cout << "Result: " << endl;
	cout << calculateExpressionInPostfixForm(postfixForm) << endl;
	
	return 0;
}