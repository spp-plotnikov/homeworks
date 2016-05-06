#pragma once
#include <iostream>


class ArithmeticTree
{
public:
    ArithmeticTree(FILE *userInputFile);
    void printTree(std::ostream &out);
    double calculateTree();
    ~ArithmeticTree();
private:
    class TreeNode
    {
    public:
        double value;
        char sign;
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;
    };

    TreeNode* readTheNode();
    double calculateTheNode(TreeNode *current);
    void printTheNode(TreeNode* current, std::ostream &out);
    void deleteTree(TreeNode *current);

    TreeNode *root = nullptr;
    FILE *input = nullptr;
    double result = 0.0;
    bool wasCalculated = false;
};

//TODO: doxigen comments
//TODO: tests
