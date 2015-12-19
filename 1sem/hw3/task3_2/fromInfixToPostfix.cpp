#include "stackServices.h"
#include "fromInfixToPostfix.h"
#include <cstring>

using namespace std;

void addToTheArray(char postfixForm[], int*, char);
void operationsForThePlusesAndMinuses(Stack *&signs, char postfixForm[], int*, char);
void operationsForTheMultiplicationsAndDivisions(Stack *&signs, char postfixForm[], int*, char);

char* infixToPostfixForm(char infixForm[])
{
	const int maxLength = 260;
	int lengthOfPostfix = 0;
	char postfixForm[maxLength] = {};

	Stack *signs = new Stack;
	push(signs, '0');  //This is "the guard".

	for (int i = 0; i < strlen(infixForm); i++)
	{
		switch (infixForm[i])
		{
		case '*':
		case '/':
		{
			operationsForTheMultiplicationsAndDivisions(signs, postfixForm, &lengthOfPostfix, infixForm[i]);
			break;
		}
		case '+':
		case '-':
		{
			operationsForThePlusesAndMinuses(signs, postfixForm, &lengthOfPostfix, infixForm[i]);
			break;
		}
		case '(':
		{
			push(signs, '(');
			break;
		}
		case ')':
		{
			char temp = viewTheTop(signs);
			while (temp != '(')
			{
				temp = pop(signs);
				addToTheArray(postfixForm, &lengthOfPostfix, temp);
				temp = viewTheTop(signs);
			}
			temp = pop(signs);
			break;
		}
		default:
		{
			if (infixForm[i] != ' ')
			{
				postfixForm[lengthOfPostfix] = infixForm[i];
				lengthOfPostfix++;
				if (i < maxLength && (infixForm[i + 1] == ' ' || infixForm[i + 1] == ')' || i == strlen(infixForm) - 1))
				{
					postfixForm[lengthOfPostfix] = ' ';
					lengthOfPostfix++;
				}
			}
		}
		}
	}

	char temp = viewTheTop(signs);
	while (temp != '0')
	{
		temp = pop(signs);
		addToTheArray(postfixForm, &lengthOfPostfix, temp);
		temp = viewTheTop(signs);
	}

	delete signs;

	char *outputData = new char[lengthOfPostfix + 1];
	for (int i = 0; i < lengthOfPostfix; i++)
	{
		outputData[i] = postfixForm[i];
	}
	outputData[lengthOfPostfix] = '\0';

	return outputData;
}

void addToTheArray(char postfixForm[], int *lengthOfPostfix, char temp)
{
	postfixForm[*lengthOfPostfix] = temp;
	postfixForm[*lengthOfPostfix + 1] = ' ';
	*lengthOfPostfix += 2;
}


void operationsForThePlusesAndMinuses(Stack *&signs, char postfixForm[], int *lengthOfPostfix, char token)
{
	char temp = viewTheTop(signs);
	while (temp != '0' && temp != '(')
	{
		temp = pop(signs);
		addToTheArray(postfixForm, lengthOfPostfix, temp);
		temp = viewTheTop(signs);
	}
	push(signs, token);
}

void operationsForTheMultiplicationsAndDivisions(Stack *&signs, char postfixForm[], int *lengthOfPostfix, char token)
{
	char temp = viewTheTop(signs);
	while (temp == '*' || temp == '/')
	{
		temp = pop(signs);
		addToTheArray(postfixForm, lengthOfPostfix, temp);
		temp = viewTheTop(signs);
	}
	push(signs, token);
}
