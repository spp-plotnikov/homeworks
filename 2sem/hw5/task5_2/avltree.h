#pragma once

/*!
 *   \brief Implementation of the module for working with the AVL-tree
 *   \author © Sasha Plotnikov Production, Ltd.
 *   \warning You must use the data types that can be compared
 */

template <typename Type>
class AVLTree
{
public:
    void add(const Type &newValue);
    void remove(const Type &target);
    bool isFound(const Type &target) const;
    /*!
     * \param sizeOfArray must be zero at the beginning because in the
     *  end it will be equal to the size of the array
     * \return pointer to array which contains content of the tree in ascending order
     * \warning you must delete an array (it is dynamic)
     */
    Type* toPresentContentInArray(int &sizeOfArray) const;
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
        TreeNode(const Type &newValue, int newHeight, TreeNode *left, TreeNode *right);

        Type value;
        int height;
        TreeNode *leftChild;
        TreeNode *rightChild;
    };


    TreeNode* addNewElement(TreeNode *parent, const Type &newValue);
    TreeNode* deleteElement(TreeNode *current, const Type &forRemoval);
    TreeNode* findMinElement(TreeNode *thisNode);
    TreeNode* rotateRight(TreeNode *thisRoot);
    TreeNode* rotateLeft(TreeNode *thisRoot);
    TreeNode* balance(TreeNode *p);
    TreeNode* removeMinElement(TreeNode *current);
    void toArrayInAscendingOrder(TreeNode *current, int &sizeOfArray, Type *array) const;
    void updateHeight(TreeNode *node);
    int balanceFactor(TreeNode *node);
    int height(TreeNode *node);


    TreeNode *root = NULL;
    int countOfValues = 0;
};


//---------------------------------------------------------


template <typename Type>
void AVLTree<Type>::add(const Type &newValue)
{
    root = addNewElement(root, newValue);
}


template <typename Type>
void AVLTree<Type>::remove(const Type &target)
{
    root = deleteElement(root, target);
}


template <typename Type>
bool AVLTree<Type>::isFound(const Type &target) const
{
    TreeNode* current = root;
    while (current)
    {
        if (current->value > target)
        {
            current = current->leftChild;
        }
        else if (current->value < target)
        {
            current = current->rightChild;
        }
        else
        {
            return true;
        }
    }
    return false;
}


template <typename Type>
Type* AVLTree<Type>::toPresentContentInArray(int &sizeOfArray) const
{
    Type *array = new Type[countOfValues + 1];
    toArrayInAscendingOrder(root, sizeOfArray, array);
    return array;
}


template <typename Type>
AVLTree<Type>::~AVLTree()
{
    while (root)
    {
        remove(root->value);
    }
}


//---------------------------------------------------------


template <typename Type>
typename AVLTree<Type>::TreeNode* AVLTree<Type>::addNewElement(TreeNode *parent, const Type &newValue)
{
    if (parent == nullptr)
    {
        TreeNode *newNode = new TreeNode(newValue, 1, NULL, NULL);
        countOfValues++;
        return newNode;
    }
    else if (newValue < parent->value)
    {
        parent->leftChild = addNewElement(parent->leftChild, newValue);
    }
    else if (newValue > parent->value)
    {
        parent->rightChild = addNewElement(parent->rightChild, newValue);
    }
    return balance(parent);
}


template <typename Type>
typename AVLTree<Type>::TreeNode* AVLTree<Type>::deleteElement(TreeNode *current, const Type &forRemoval)
{
    if (current)
    {
        if (forRemoval < current->value)
        {
            current->leftChild = deleteElement(current->leftChild, forRemoval);
        }
        else if (forRemoval > current->value)
        {
            current->rightChild = deleteElement(current->rightChild, forRemoval);
        }
        else
        {
            TreeNode *left = current->leftChild;
            TreeNode *right = current->rightChild;
            delete current;
            countOfValues--;
            if (right == NULL)
            {
                return left;
            }
            TreeNode *minElement = findMinElement(right);
            minElement->rightChild = removeMinElement(right);
            minElement->leftChild = left;
            return balance(minElement);
        }
        return balance(current);
    }
}


template <typename Type>
typename AVLTree<Type>::TreeNode* AVLTree<Type>::findMinElement(TreeNode *thisNode)
{
    while (thisNode->leftChild != nullptr)
    {
        thisNode = thisNode->leftChild;
    }
    return thisNode;
}


template <typename Type>
typename AVLTree<Type>::TreeNode* AVLTree<Type>::rotateRight(TreeNode *thisRoot)
{
    TreeNode* pivot = thisRoot->leftChild;
    thisRoot->leftChild = pivot->rightChild;
    pivot->rightChild = thisRoot;
    updateHeight(thisRoot);
    updateHeight(pivot);
    return pivot;
}


template <typename Type>
typename AVLTree<Type>::TreeNode* AVLTree<Type>::rotateLeft(TreeNode *thisRoot)
{
    TreeNode* pivot = thisRoot->rightChild;
    thisRoot->rightChild = pivot->leftChild;
    pivot->leftChild = thisRoot;
    updateHeight(thisRoot);
    updateHeight(pivot);
    return pivot;
}


template <typename Type>
typename AVLTree<Type>::TreeNode* AVLTree<Type>::balance(TreeNode *p)
{
    updateHeight(p);

    if (balanceFactor(p) == 2)
    {
        if (balanceFactor(p->rightChild) < 0)
            p->rightChild = rotateRight(p->rightChild);

        return rotateLeft(p);
    }

    if (balanceFactor(p) == -2)
    {
        if (balanceFactor(p->leftChild) > 0)
            p->leftChild = rotateLeft(p->leftChild);

        return rotateRight(p);
    }

    return p;
}


template <typename Type>
typename AVLTree<Type>::TreeNode* AVLTree<Type>::removeMinElement(TreeNode *current)
{
    if (current->leftChild == NULL)
    {
        return current->rightChild;
    }
    current->leftChild = removeMinElement(current->leftChild);
    return balance(current);
}


template <typename Type>
void AVLTree<Type>::toArrayInAscendingOrder(TreeNode *current, int &sizeOfArray, Type *array) const
{
    if (current)
    {
        toArrayInAscendingOrder(current->leftChild, sizeOfArray, array);
        array[sizeOfArray] = current->value;
        sizeOfArray++;
        toArrayInAscendingOrder(current->rightChild, sizeOfArray, array);
    }
}


template <typename Type>
void AVLTree<Type>::updateHeight(TreeNode *node)
{
    int heightLeft = height(node->leftChild);
    int heightRight = height(node->rightChild);
    node->height = ((heightLeft > heightRight) ? heightLeft : heightRight) + 1;
}


template <typename Type>
int AVLTree<Type>::balanceFactor(TreeNode *node)
{
    return height(node->rightChild) - height(node->leftChild);
}


template <typename Type>
int AVLTree<Type>::height(TreeNode *node)
{
    return node ? node->height : 0;
}


//---------------------------------------------------------


template <typename Type>
AVLTree<Type>::TreeNode::TreeNode(const Type &newValue, int newHeight, TreeNode *left, TreeNode *right)
{
    value = newValue;
    height = newHeight;
    leftChild = left;
    rightChild = right;
}
