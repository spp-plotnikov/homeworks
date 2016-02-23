#include "arraylist.h"
#include <iostream>

using namespace std;

ArrayList::ArrayList()
{
    size = 32;
    quantity = 0;
    array = new int[size + 1];
}


void ArrayList::add(int newElement)
{
    array[quantity] = newElement;
    quantity++;
    if (quantity >= size)
    {
        size *= 2;
        resize();
    }
}


bool ArrayList::isFound(int target) const
{
    for (int i = 0; i < quantity; i++)
    {
        if (array[i] == target)
            return true;
    }
    return false;
}


void ArrayList::remove(int target)
{
    int index = 0;
    for (; index < quantity; index++)
    {
        if (array[index] == target)
        {
            quantity--;
            break;
        }
    }

    for (int i = index; i < quantity; i++)
    {
        array[i] = array[i + 1];
    }

    if (size > 32 && quantity == size / 2 - 1)
    {
        size /= 2;
        resize();
    }
}


void ArrayList::print() const
{
    for (int i = 0; i < quantity; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}


ArrayList::~ArrayList()
{
    delete []array;
}


void ArrayList::resize()
{
    int *temp = new int[size + 1];
    for (int i = 0; i < quantity; i++)
    {
        temp[i] = array[i];
    }
    delete []array;
    array = temp;
}
