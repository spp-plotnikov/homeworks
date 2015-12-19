#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "fromInfixToPostfix.h"
#include "calculatePostfixExpression.h"


using namespace std;

int main()
{
	cout << "This calculator was developed by company \"Sasha Plotnikov Production\", ltd." << endl;
	cout << "You can calculate any numbers, use parentheses and the signs *, +, -, /" << endl;
	cout << "For example: 1 + 2 * (15 - 4) / 2,5 * 255 + 3,25" << endl;
	cout << "Please enter the expression" << endl;

	const int maxLength = 260;
	char infixForm[maxLength] = {};
	cin.getline(infixForm, maxLength);

	cout << "The result of the calculations: ";
	char *postfixForm = infixToPostfixForm(infixForm);
	cout << calculateExpressionInPostfixForm(postfixForm) << endl;
	
	delete []postfixForm;
	
	return 0;
}