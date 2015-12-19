#include "string.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	cout << "This app demonstrates the capabilities of the module ";
	cout << "for the abstract data type String, designed ";
	cout << "by Alexandr Plotnikov." << endl;

	const int maxLength = 1024; //  It is assumed that the length does not exceed 1024
	char stringOne[maxLength] = {};
	char stringTwo[maxLength] = {};
	cout << "Please enter string No1" << endl;
	cin.getline(stringOne, maxLength);
	cout << "Please enter string No2" << endl;
	cin.getline(stringTwo, maxLength);

	String *string1 = createString(stringOne);
	String *string2 = createString(stringTwo);
	cout << "This module is able to create strings." << endl;
	cout << "Your two strings successfully created!" << endl;

	cout << endl << "This module can copy strings." << endl;
	String *string3 = clone(string1);
	cout << "For example this is a copy of string No1: ";
	printTheString(string3);
	cout << endl;

	cout << endl << "The module can concatenate strings." << endl;
	cout << "For example, the concatenation of string 1 and string 2: " << endl;
	concat(string1, string2);
	printTheString(string1);
	cout << endl << "By the way, you have ability to concatenate ";
	cout << "strings and arrays of characters (char*)" << endl;
	cout << "For example, the concatenation of string 1 and ";
	cout << "array of characters 1: " << endl;
	concatForChar(string1, stringOne);
	printTheString(string1);
	cout << endl;

	cout << endl << "You can check strings for equality" << endl;
	cout << "For strings 1 and 2: ";
	if (isTheSame(string1, string2))
	{
		cout << "Equal" << endl;
	}
	else
	{
		cout << "Unequal" << endl;
	}

	cout << endl << "If you want to know the string ";
	cout << "length the function will help you with this." << endl;
	cout << "The length of the first string: ";
	cout << lengthOfString(string1) << endl;

	cout << endl << "Also, you can check the string on emptiness." << endl;
	if (isEmpty(string2))
	{
		cout << "String No2 is empty!" << endl;
	}
	else
	{
		cout << "String No2 is not empty!" << endl;
	}

	cout << endl << "Of course, you can get a substring." << endl;
	cout << "The substring of the string No1 from 2 to 3 symbol: ";
	String *string4 = getSubstring(string1, 2, 3);
	printTheString(string4);
	cout << endl;

	cout << endl << "But that's not all!" << endl;
	cout << "Please enter any positive big integer." << endl;
	int quantity = 0;
	cin >> quantity;
	for (int i = 1; i <= quantity; i++)
	{
		concat(string1, string2);
	}
	printTheString(string1);
	cout << endl;
	cout << "We concatenated strings " << quantity << " times. ";
	cout << "You have made sure that the string ";
	cout << "can be expanded in unlimited range." << endl;

	deleteString(string1);
	deleteString(string2);
	deleteString(string3);
	deleteString(string4);
	return 0;
}