#pragma once
#include <iostream>

/*!
 * \brief The module for working with the arithmetic tree
 * \author © Sasha Plotnikov Production, Ltd.
 */

class ArithmeticTree
{
public:
    /// \param userInputFile is the file containing the tree
    ArithmeticTree(FILE *userInputFile);
    /// \param out is the place of printing
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
