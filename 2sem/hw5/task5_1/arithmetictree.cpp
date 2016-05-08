#include "arithmetictree.h"

ArithmeticTree::ArithmeticTree(FILE *userInputFile)
{
    input = userInputFile;
}


void ArithmeticTree::printTree(std::ostream &out)
{
    root->print(out);
}


double ArithmeticTree::calculateTree()
{
    if (!wasCalculated)
    {
        root = readTheNode();
        result = root->getValue();
        wasCalculated = true;
    }
    return result;
}


ArithmeticTree::~ArithmeticTree()
{
    delete root;
}


//--------------------------------------------------------------


ArithmeticTree::TreeNode*  ArithmeticTree::readTheNode()
{
    char symbol = fgetc(input);
    while (symbol == ' ' || symbol == ')')
    {
        symbol = fgetc(input);
    }
    TreeNode *newNode = nullptr;
    if (symbol == '(')
    {
        newNode = new OperationTreeNode(fgetc(input), readTheNode(), readTheNode());
    }
    else
    {
        double number = 0.0;
        while (symbol != ')' && symbol != '\0' && symbol != '\n' && symbol != ' ')
        {
            number *= 10;
            number += (int(symbol) - int('0'));
            symbol = fgetc(input);
        }
        newNode = new NumberTreeNode(number);
    }
    return newNode;
}


ArithmeticTree::NumberTreeNode::NumberTreeNode(double valueOfNode)
{
    value = valueOfNode;
}


ArithmeticTree::OperationTreeNode::OperationTreeNode(char operation, TreeNode *leftOperand, TreeNode *rightOperand)
{
    sign = operation;
    left = leftOperand;
    right = rightOperand;
}


double ArithmeticTree::NumberTreeNode::getValue()
{
    return value;
}


double ArithmeticTree::OperationTreeNode::getValue()
{
    double leftValue = left->getValue();    //  left never be nullptr
    double rightValue = right->getValue();  //  right never be nullptr

    switch (sign)
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


void ArithmeticTree::NumberTreeNode::print(std::ostream &out) const
{
    out << value;
}


void ArithmeticTree::OperationTreeNode::print(std::ostream &out) const
{
    out << '(';
    left->print(out);
    out << ' ' << sign << ' ';
    right->print(out);
    out << ')';
}


ArithmeticTree::OperationTreeNode::~OperationTreeNode()
{
    delete left;
    delete right;
}
