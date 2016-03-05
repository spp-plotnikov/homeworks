#include <cstring>
#include "calculator.h"
#include "stack.h"
#include "arraystack.h"
#include "pointerstack.h"

Calculator::Calculator()
{
    numbers->push(0);   //  This is "the guard".
    signs->push('0');   //  This is "the guard".
}


double Calculator::calculate(char *infixForm)
{
    return calculateExpressionInPostfixForm(infixToPostfixForm(infixForm));
}


Calculator::~Calculator()
{
    delete numbers;
    delete signs;
}


//--------------------------------------------------------------


char* Calculator::infixToPostfixForm(char infixForm[])
{
    for (int i = 0; i < strlen(infixForm); i++)
    {
        switch (infixForm[i])
        {
        case '*':
        case '/':
        {
            operationsForTheMultiplicationsAndDivisions(infixForm[i]);
            break;
        }
        case '+':
        case '-':
        {
            operationsForThePlusesAndMinuses(infixForm[i]);
            break;
        }
        case '(':
        {
            signs->push('(');
            break;
        }
        case ')':
        {
            char temp = signs->viewTheTop();
            while (temp != '(')
            {
                temp = signs->pop();
                addToTheArray(temp);
                temp = signs->viewTheTop();
            }
            temp = signs->pop();
            break;
        }
        default:
        {
            if (infixForm[i] != ' ')
            {
                postfixForm[lengthOfPostfix] = infixForm[i];
                lengthOfPostfix++;
                if (i < maxLength && (infixForm[i + 1] == ' ' || infixForm[i + 1] == ')' || i == strlen(infixForm) - 1))
                {
                    postfixForm[lengthOfPostfix] = ' ';
                    lengthOfPostfix++;
                }
            }
        }
        }
    }

    char temp = signs->viewTheTop();
    while (temp != '0')
    {
        temp = signs->pop();
        addToTheArray(temp);
        temp = signs->viewTheTop();
    }
    postfixForm[lengthOfPostfix] = '\0';
    return postfixForm;
}


void Calculator::addToTheArray(char temp)
{
    postfixForm[lengthOfPostfix] = temp;
    postfixForm[lengthOfPostfix + 1] = ' ';
    lengthOfPostfix += 2;
}


void Calculator::operationsForThePlusesAndMinuses(char token)
{
    char temp = signs->viewTheTop();
    while (temp != '0' && temp != '(')
    {
        temp = signs->pop();
        addToTheArray(temp);
        temp = signs->viewTheTop();
    }
    signs->push(token);
}


void Calculator::operationsForTheMultiplicationsAndDivisions(char token)
{
    char temp = signs->viewTheTop();
    while (temp == '*' || temp == '/')
    {
        temp = signs->pop();
        addToTheArray(temp);
        temp = signs->viewTheTop();
    }
    signs->push(token);
}


double Calculator::calculateExpressionInPostfixForm(char postfixForm[])
{
    for (int i = 1; i < strlen(postfixForm); i++)
    {
        if (postfixForm[i] == ' ' && postfixForm[i - 1] - '0' >= 0 && postfixForm[i - 1] - '0' <= 9)
        {
            int k = i - 1;
            double orderOfMagnitude = 1.0;
            double number = 0.0;
            while (postfixForm[k] != ' ' && k >= 0)
            {
                if (postfixForm[k] != ',')
                {
                    number += orderOfMagnitude * (postfixForm[k] - '0');
                    k--;
                    orderOfMagnitude *= 10.0;
                }
                else
                {
                    number /= orderOfMagnitude;
                    orderOfMagnitude = 1.0;
                    k--;
                }
            }
            numbers->push(number);
        }
        else if (postfixForm[i] == '-' || postfixForm[i] == '/' || postfixForm[i] == '+' || postfixForm[i] == '*')
        {
            double x = numbers->pop();
            double y = numbers->pop();
            switch (postfixForm[i])
            {
            case '-':
            {
                y -= x;
                break;
            }
            case '+':
            {
                y += x;
                break;
            }
            case '/':
            {
                y /= x;
                break;
            }
            case '*':
            {
                y *= x;
                break;
            }
            }
            numbers->push(y);
        }
    }
    return numbers->pop();
}
