#include "bag.h"

void Bag::add(int value)
{
    tree->add(value);
}


bool Bag::remove(int value)
{
    if (!find(value))
        return false;

    tree->remove(value);
    return true;
}


bool Bag::find(int value) const
{
    return (getCount(value) > 0);
}


unsigned int Bag::getCount(int value) const
{
    return tree->getCount(value);
}


int* Bag::getContent(int &arraySize) const
{
    return tree->toPresentContentInArray(arraySize);
}


Bag::~Bag()
{
    delete tree;
}
