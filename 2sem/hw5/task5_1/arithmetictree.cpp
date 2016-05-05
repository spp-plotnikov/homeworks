#include "arithmetictree.h"

ArithmeticTree::ArithmeticTree(FILE *userInputFile)
{
    input = userInputFile;
}


void ArithmeticTree::printTree(ostream &out)
{
    printTheNode(root, out);
}


double ArithmeticTree::calculateTree()
{
    if (!wasCalculated)
    {
        result = calculateTheNode(root);
        wasCalculated = true;
    }
    return result;
}


ArithmeticTree::~ArithmeticTree()
{
    deleteTree(root);
}


//--------------------------------------------------------------


ArithmeticTree::TreeNode*  ArithmeticTree::readTheNode()
{
    char symbol = fgetc(input);
    while (symbol == ' ' || symbol == ')')
    {
        symbol = fgetc(input);
    }
    TreeNode *newNode = new TreeNode;
    if (symbol == '(')
    {
        newNode->sign = fgetc(input);
        newNode->left = readTheNode();
        newNode->right = readTheNode();
    }
    else
    {
        newNode->sign = '$';
        double number = 0.0;
        while (symbol != ')' && symbol != '\0' && symbol != '\n' && symbol != ' ')
        {
            number *= 10;
            number += (int(symbol) - int('0'));
            symbol = fgetc(input);
        }
        newNode->value = number;
    }
    return newNode;
}


double ArithmeticTree::calculateTheNode(TreeNode *current)
{
    if (current->sign == '$')
    {
        return current->value;
    }
    else
    {
        double leftValue = calculateTheNode(current->left);
        double rightValue = calculateTheNode(current->right);

        switch (current->sign)
        {
        case '*':
        {
            return leftValue * rightValue;
            break;
        }
        case '/':
        {
            return leftValue / rightValue;
            break;
        }
        case '+':
        {
            return leftValue + rightValue;
            break;
        }
        case '-':
        {
            return leftValue - rightValue;
            break;
        }
        }
    }
}


void ArithmeticTree::printTheNode(TreeNode *current, ostream &out)
{

    if (currentNode->sign == '$')
    {
        out << currentNode->value;
    }
    else
    {
        out << '(';
        printTheNode(currentNode->left, out);
        out << ' ' << currentNode->sign << ' ';
        printTheNode(currentNode->right, out);
        out << ')';
    }
}


void ArithmeticTree::deleteTree(TreeNode *current)
{
    deleteTree(current->left);
    deleteTree(current->right);
    if (current)
        delete current;
}
