#pragma once
#include "stack.h"
#include "arraystack.h"
#include "pointerstack.h"

class Calculator
{
public:
    Calculator();
    double calculate(char *infixForm);
    ~Calculator();

    static const int maxLength = 260;

private:
    char* infixToPostfixForm(char infixForm[]);
    void addToTheArray(char temp);
    void operationsForThePlusesAndMinuses(char token);
    void operationsForTheMultiplicationsAndDivisions(char token);
    double calculateExpressionInPostfixForm(char postfixForm[]);

    Stack<double> *numbers = new PointerStack<double>();   //  You can use ArrayStack also
    Stack<char> *signs = new PointerStack<char>();   //  You can use ArrayStack also
    int lengthOfPostfix = 0;
    char postfixForm[maxLength] = {};
};
