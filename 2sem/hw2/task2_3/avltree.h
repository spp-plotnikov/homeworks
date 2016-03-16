#pragma once
#include "sortedset.h"

/// Implementation of the module for working with the sorted set (on the basis of the tree).
/*!
    \author © Sasha Plotnikov Production, Ltd.
    \warning You must use the data types that can be compared

    The child class. Inherits from SortedSet.
    The class uses the AVL-trees to implement SortedSet functionality
*/

template <typename Type>
class AVLTree : public SortedSet<Type>
{
public:
    AVLTree();
    void add(Type *newValue);
    void remove(Type *target);
    bool isFound(Type *target) const;
    ~AVLTree();

private:
    /// Class for working with the nodes of tree
    class TreeNode
    {
    public:
        /*!
           Constructor creates new node with value newValue,
           height and pointers to the left and right children
        */
        TreeNode(const Type *newValue, int newHeight, TreeNode *left, TreeNode *right);
        ~TreeNode();

        Type *value;
        int height;
        TreeNode *leftChild;
        TreeNode *rightChild;
    };


    TreeNode* addNewElement(TreeNode *parent, Type *newValue);
    TreeNode* deleteElement(TreeNode*, Type *forRemoval);


    TreeNode *root = NULL;
};


//---------------------------------------------------------


template <typename Type>
void AVLTree<Type>::add(Type *newValue)
{
    root = addNewElement(root, newValue);
}


template <typename Type>
void AVLTree<Type>::remove(Type *target)
{
    root = deleteElement(root, target);
}


template <typename Type>
TreeNode* AVLTree<Type>::addNewElement(TreeNode *parent, Type *newValue)
{
    if (parent == NULL)
    {
        TreeNode *newNode = new TreeNode(newValue, 1, NULL, NULL);
        return newNode;
    }
    else if (*newValue < *parent->value)
    {
        parent->leftChild = addNewElement(parent->leftChild, newValue);
    }
    else if (*newValue > *parent->value)
    {
        parent->rightChild = addNewElement(parent->rightChild, newValue);
    }
    return balance(parentNode);
}
