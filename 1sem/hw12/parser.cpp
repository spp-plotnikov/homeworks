#include "floatAnalyzer.h"
#include "parser.h"
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <cstdlib>
#include <cstdio>

void skipSpaces(char*, int&);
bool isCorrectNextToken(char*, int&);
bool isCorrectAhead(char*, int&);
bool isSign(char);
bool signInsideFloat(char*, int);
bool starting(char*, int&);


bool isCorrectExpression(char *expression)
{
	int index = 0;
	skipSpaces(expression, index);
	return starting(expression, index);
}


void skipSpaces(char *expression, int &index)
{
	while (isspace(expression[index]))
	{
		index++;
	}
}


bool starting(char *expression, int &index)
{
	if (expression[index] == '+' || expression[index] == '-')
	{
		index++;
	}
	return isCorrectNextToken(expression, index);
}


bool isCorrectNextToken(char *expression, int &index)
{
	skipSpaces(expression, index);
	int start = index;
	while (index < strlen(expression))
	{
		if (isSign(expression[index]) && !signInsideFloat(expression, index) || isspace(expression[index]))
			break;
		index++;
	}
	int end = index;
	int length = end - start;
	char *floatCandidate = new char[length + 1];
	floatCandidate[length] = '\0';
	for (int i = 0; i < length; i++)
		floatCandidate[i] = expression[start + i];

	bool isFloat = isCorrectFloat(floatCandidate);
	delete []floatCandidate;

	return (isFloat && isCorrectAhead(expression, index));
}


bool isSign(char symbol)
{
	return (symbol == '-' || symbol == '+' || symbol == '/' || symbol == '*');
}


bool signInsideFloat(char *expression, int index)
{
	return (index > 1 && isExponentSign(expression[index - 1]));
}


bool isCorrectAhead(char *expression, int &index)
{
	skipSpaces(expression, index);
	if (index == strlen(expression))
	{
		return true;
	}
	if (isSign(expression[index]))
	{
		index++;
	}
	else
	{
		return false;
	}
	return isCorrectNextToken(expression, index);
}
