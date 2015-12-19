#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    cout << "This application checks the balance of the parentheses in sentence" << endl;
    cout << "Please enter the string" << endl;

    const int maxLength = 260;   //It is assumed that the length does not exceed 260
    char thisString[maxLength] = {};
    cin.getline(thisString, maxLength);

    int balance = 0;
    bool isBalanced = true;
    int length = strlen(thisString);
    for (int i = 0; i < length; i++)
    {
        if (thisString[i] == '(')
        {
            balance++;
        }
        if (thisString[i] == ')')
        {
            balance--;
        }
        if (balance < 0)
        {
            isBalanced = false;
        }
    }
    if (balance != 0)
    {
        isBalanced = false;
    }
    if (isBalanced)
    {
        cout << "Balance of the parentheses been respected" << endl;
    }
    else
    {
        cout << "Balance of the parentheses had not been respected" << endl;
    }
    return 0;
}
