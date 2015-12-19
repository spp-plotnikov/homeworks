#include "calculatePostfixExpression.h"
#include <cstring>
#include "stackServicesDouble.h"

using namespace std;

double calculateExpressionInPostfixForm(char postfixForm[])
{

	StackOfDoubles *numbers = new StackOfDoubles;
	push(numbers, 0); //This is the  guard.
	for (int i = 1; i < strlen(postfixForm); i++)
	{
		if (postfixForm[i] == ' ' && postfixForm[i - 1] - '0' >= 0 && postfixForm[i - 1] - '0' <= 9)
		{
			int k = i - 1;
			double orderOfMagnitude = 1.0;
			double number = 0.0;
			while (postfixForm[k] != ' ' && k >= 0)
			{
				if (postfixForm[k] != ',')
				{
					number += orderOfMagnitude * (postfixForm[k] - '0');
					k--;
					orderOfMagnitude *= 10.0;
				}
				else
				{
					number /= orderOfMagnitude;
					orderOfMagnitude = 1.0;
					k--;
				}
			}
			push(numbers, number);
		}
		else if (postfixForm[i] == '-' || postfixForm[i] == '/' || postfixForm[i] == '+' || postfixForm[i] == '*')
		{
			double x = pop(numbers);
			double y = pop(numbers);
			switch (postfixForm[i])
			{
			case '-':
			{
				y -= x;
				break;
			}
			case '+':
			{
				y += x;
				break;
			}
			case '/':
			{
				y /= x;
				break;
			}
			case '*':
			{
				y *= x;
				break;
			}
			}
			push(numbers, y);
		}
	}
	double outputData = pop(numbers);
	delete numbers;
	return outputData;
}