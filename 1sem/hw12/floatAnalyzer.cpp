#include "floatAnalyzer.h"
#include <iostream>
#include <cstring>
#include <cctype>

bool isSign(char);
bool isPoint(char);

bool isCorrectFloat(char *string)
{
	enum State
	{
		startingState,
		integerState,
		pointState,
		fractionalPartState,
		exponentSymbolState,
		exponentSignState,
		exponentState
	};

	char current = '\0';
	State state = startingState;
	for (int i = 0; i < strlen(string); i++)
	{
		current = string[i];
		switch (state)
		{
		case startingState:
		{
			if (isdigit(current))
			{
				state = integerState;
				break;
			}
			else
			{
				return false;
			}
		}
		case integerState:
		{
			if (isExponentSign(current))
			{
				state = exponentSymbolState;
			}
			else if (isPoint(current))
			{
				state = pointState;
			}
			else if (!isdigit(current))
			{
				return false;
			}
			break;
		}
		case pointState:
		{
			if (isdigit(current))
			{
				state = fractionalPartState;
			}
			else
			{
				return false;
			}
			break;
		}
		case fractionalPartState:
		{
			if (isExponentSign(current))
			{
				state = exponentSymbolState;
			}
			else if (!isdigit(current))
			{
				return false;
			}
			break;
		}
		case exponentSymbolState:
		{
			if (isSign(current))
			{
				state = exponentSignState;
			}
			else if (isdigit(current))
			{
				state = exponentState;
			}
			else
			{
				return false;
			}
			break;
		}
		case exponentSignState:
		{
			if (isdigit(current))
			{
				state = exponentState;
			}
			else
			{
				return false;
			}
			break;
		}
		case exponentState:
		{
			if (!isdigit(current))
			{
				return false;
			}
			break;
		}
		}
	}
	return (state == integerState || state == fractionalPartState || state == exponentState);
}


bool isSign(char symbol)
{
	return (symbol == '-' || symbol == '+');
}


bool isExponentSign(char symbol)
{
	return (symbol == 'e' || symbol == 'E');
}


bool isPoint(char symbol)
{
	return (symbol == '.' || symbol == ',');   //  the comma - for Russian users
}