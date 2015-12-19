#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

void toUpCase(char thisString[], int);

using namespace std;

int main()
{
    cout << "This application is looking for occurrence of a substring in a string" << endl;

    cout << "Please enter the string" << endl;
    char thisString[260] = {};   //It is assumed that the length does not exceed 260
    cin.getline(thisString, 260);

    cout << "Please enter the substring" << endl;
    char subString[260] = {};   //It is assumed that the length does not exceed 260
    cin.getline(subString, 260);

    int quantity = 0;
    const int lengthOfSubstring = strlen(subString);
    const int lengthOfString = strlen(thisString);

    toUpCase(thisString, lengthOfString);
    toUpCase(subString, lengthOfSubstring);

    for (int i = 0; i < lengthOfString; i++)
    {
        bool isTheSame = true;
        for (int j = 0; j < lengthOfSubstring; j++)
        {
            if (thisString[i+j] != subString[j])
            {
                isTheSame = false;
                break;
            }
        }
        if (isTheSame)
        {
            quantity++;
        }
    }

    cout << "This substring found in the string " << quantity << " times" << endl;
    return 0;
}


void toUpCase(char thisString[], int lengthOfString)
{
    for (int i = 0; i < lengthOfString; i++)
    {
        thisString[i] = toupper(thisString[i]);
    }
}
