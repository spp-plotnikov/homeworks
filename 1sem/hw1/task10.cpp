#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

bool checkString(char thisString[]);

int main()
{
    cout << "This application checks whether a string is a palindrome" << endl;
    cout << "Please enter the string, and press Enter" << endl;

    char thisString[260] = {};
    cin.getline(thisString, 260); //It is assumed that the length does not exceed 260

    if (checkString(thisString))
    {
        cout << "This is a palindrome" << endl;
    }
    else
    {
        cout << "This is not a palindrome" << endl;
    }

    return 0;
}


bool checkString(char thisString[])
{
    bool control = true;
    int length = strlen(thisString);

    for (int i = 0; i <= (length / 2); i++)
    {
        thisString[i] = towlower(thisString[i]);  //Lower register (only the English alphabet)
        thisString[length - i - 1] = towlower(thisString[length - i - 1]);

        if (thisString[i] != thisString[length - i - 1])
        {
            control = false;
            break;
        }
    }

    return control;
}
