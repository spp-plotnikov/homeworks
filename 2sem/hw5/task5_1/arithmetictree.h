#pragma once


class ArithmeticTree
{
public:
    ArithmeticTree(char *string);
    void printTree();
    double calculateTree();
    ~ArithmeticTree();
private:
    class TreeNode
    {
        double value;
        char sign;
        TreeNode *left = NULL;
        TreeNode *right = NULL;
    };

    TreeNode *root = NULL;
//    double result = 0.0;
//    bool wasCalculated = false;
};

TODO: doxigen comments
TODO: tests
