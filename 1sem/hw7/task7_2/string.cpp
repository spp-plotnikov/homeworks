#include "string.h"
#include <iostream>
#include <cstring>

using namespace std;

struct String
{
	int length = 0;
	char *line = nullptr;
};


String* createString(const char *line)
{
	String *newLine = new String;
	newLine->length = strlen(line);
	char *temp = new char[newLine->length + 1];
	strcpy(temp, line);
	newLine->line = temp;
	return newLine;
}


void deleteString(String *forRemoval)
{
	delete []forRemoval->line;
	delete forRemoval;
}


String* clone(String *source)
{
	return createString(source->line);
}


void concatForChar(String *string1, const char *string2)
{
	const int length = string1->length + strlen(string2);
	char *target = new char[length + 1];
	strcpy(target, string1->line);
	strcat(target, string2);
	delete []string1->line;
	string1->line = target;
	string1->length = length;
}


void concat(String *string1, String *string2)
{
	concatForChar(string1, string2->line);
}


bool isTheSame(String *string1, String *string2)
{
	return !(strcmp(string1->line, string2->line));
}


int lengthOfString(String *thisString)
{
	return thisString->length;
}


bool isEmpty(String *thisString)
{
	return thisString->length == 0;
}


String* getSubstring(String *thisString, int start, int end)
{
	start--;
	end--;
	const int length = end - start + 1;
	char *temp = new char[length + 1];
	temp[length] = '\0';
	int k = 0;
	for (int i = start; i <= end; i++)
	{
		temp[k] = thisString->line[i];
		k++;
	}
	String *result = createString(temp);
	delete []temp;
	return result;
}


char* stringToChar(String *thisString)
{
	char *temp = new char[thisString->length + 1];
	strcpy(temp, thisString->line);
	return temp;
}


void printTheString(String *thisString)
{
	cout << thisString->line;
}
