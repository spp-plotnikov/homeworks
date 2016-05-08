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
    /// \returns result of expression represented in the tree
    double calculateTree();
    ~ArithmeticTree();
private:
    class TreeNode
    {
    public:
        virtual double getValue() = 0;
        virtual void print(std::ostream &out) const = 0;
        virtual ~TreeNode() {}
    };

    class NumberTreeNode : public TreeNode
    {
    public:
        NumberTreeNode(double valueOfNode);
        double getValue();
        void print(std::ostream &out) const;
        ~NumberTreeNode() {}

    private:
        double value;
    };

    class OperationTreeNode : public TreeNode
    {
    public:
        OperationTreeNode(char operation, TreeNode *leftOperand, TreeNode *rightOperand);
        double getValue();
        void print(std::ostream &out) const;
        ~OperationTreeNode();

    private:
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;
        char sign;
    };

    TreeNode* readTheNode();

    TreeNode *root = nullptr;
    FILE *input = nullptr;
    double result = 0.0;
    bool wasCalculated = false;
};
