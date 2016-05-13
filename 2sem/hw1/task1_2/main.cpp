#include <QCoreApplication>
#include <iostream>
#include <cstring>
#include "calculatortest.h"
#include "calculator.h"
#include "stacktest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    StackTest stackTest;
    CalculatorTest calculatorTest;
    QTest::qExec(&stackTest);
    QTest::qExec(&calculatorTest);

    cout << "This calculator was developed by company \"Sasha Plotnikov Production\", ltd." << endl;
    cout << "You can calculate any numbers, use parentheses and the signs *, +, -, /" << endl;
    cout << "For example: 1 + 2 * (15 - 4) / 2,5 * 255 + 3,25" << endl;
    cout << "Please enter the expression" << endl;

    char infixForm[Calculator::maxLength] = {};
    cin.getline(infixForm, Calculator::maxLength);

    cout << "The result of the calculations: ";
    Calculator *calculator = new Calculator;
    cout << calculator->calculate(infixForm) << endl;
    delete calculator;

    return a.exec();
}
