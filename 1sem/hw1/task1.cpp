#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(void)
{
    cout << "This application returns the value of the expression x^4 + x^3 + x^2 + x + 1" << endl;
    cout << "Please enter x" << endl;

    long lVariableX = 0;
    cin >> lVariableX;

    const long lSquaredX = lVariableX * lVariableX;

    cout << "The result of calculations: " << (lSquaredX + lVariableX) * (lSquaredX + 1) + 1 << endl;
    return 0;
}
