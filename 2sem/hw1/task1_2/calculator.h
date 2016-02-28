#pragma once
#include "stack.h"
#include "arraystack.h"
#include "pointerstack.h"

class Calculator
{
public:
    static const int maxLength = 260;
public:
    Calculator();
    double calculate(char*);
    ~Calculator();
private:
    char* infixToPostfixForm(char*);
    void addToTheArray(char);
    void operationsForThePlusesAndMinuses(char);
    void operationsForTheMultiplicationsAndDivisions(char);
    double calculateExpressionInPostfixForm(char*);
private:
    Stack<double> *numbers;
    Stack<char> *signs;
    int lengthOfPostfix;
    char postfixForm[maxLength] = {};
};
