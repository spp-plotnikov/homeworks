#pragma once
#include "list.h"

/// Implementation of the module for working with the list (arrays).
/*!
    \author © Sasha Plotnikov Production, Ltd.

    The child class. Inherits from List.
    The class uses the arrays to implement List functionality
*/

class ArrayList : public List
{
public:
    ArrayList() {}
    virtual void add(int newElement);
    virtual bool isFound(int target) const;
    virtual void remove(int target);
    virtual void print() const;
    virtual ~ArrayList();
private:
    /*!
       \brief this method resizes the array

       If the array is full or filled to half, then
       this method increases or reduces its size by half, respectively.
    */
    void resize();

    int size = 32;  ///< Starting size of the array
    int quantity = 0;
    int *array = new int[size + 1];

};
