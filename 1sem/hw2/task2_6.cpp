#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    cout << "Hi, User! This is the game Bulls and Cows!" << endl;
    cout << "You can read the rules on the website: http://goo.gl/J1LKti" << endl;
    cout << "Let's start!" << endl;
    cout << "Enter the number and press the Enter" << endl;

    bool isDigitAlreadyUsed[10];
    for (int i = 0; i < 10; i++)
    {
        isDigitAlreadyUsed[i] = false;
    }
    const int quantityOfDigits = 4;   //We have only four digits.
    int digits[quantityOfDigits] = {};

    srand(time(0));
    for (int i = 0; i < quantityOfDigits; i++)
    {
        int digit = rand() % 10;
        while (isDigitAlreadyUsed[digit])
        {
            digit = rand() % 10;
        }
        digits[i] = digit;
        isDigitAlreadyUsed[digit] = true;
    }

    int userDigits[quantityOfDigits] = {};
    int quantityOfAttempts = 0;
    int cows = 0;
    int bulls = 0;
    do
    {
        cows = 0;
        bulls = 0;
        for (int i = 0; i < quantityOfDigits; i++)
        {
            cin >> userDigits[i];
            if (userDigits[i] == digits[i])
            {
                bulls++;
            }
            else if (isDigitAlreadyUsed[userDigits[i]])
            {
                cows++;
            }
        }

        quantityOfAttempts++;
        cout << "Bulls = " << bulls << "; Cows = " << cows << endl;
    } while (bulls != quantityOfDigits);

    cout << "Congratulations! You have won! Quantity of attempts: " << quantityOfAttempts << endl;

    return 0;
}
