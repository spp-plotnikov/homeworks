#include "fromInfixToPostfix.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void main()
{
	cout << "This application converts from infix form to postfix" << endl;
	cout << "Please enter the expression and press Enter" << endl;

	const int maxLength = 260;
	char infixForm[maxLength] = {};

	cin.getline(infixForm, maxLength);

	cout << "Result: " << endl;
	char *postfixForm = infixToPostfixForm(infixForm);
	cout << postfixForm;

	delete []postfixForm;
}