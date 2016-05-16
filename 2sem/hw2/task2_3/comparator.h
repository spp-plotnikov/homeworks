#pragma once
#include "list.h"

template <typename Type>
class Comparator
{
public:
    /*!
     * \brief compares two elements (for example lists by length)
     * \warning You must use the data types that can be compared
     * \return 1, if the first element is bigger than second,
     * 0, if the elements are equal by size (length)
     * -1, if second elenent is bigger than first
     */
    static int compare(const Type *element1, const Type *element2);
};


//---------------------------------------------------------------------


template <typename Type>
int Comparator<Type>::compare(const Type *element1, const Type *element2)
{
    if (*element1 > *element2)
    {
        return 1;
    }
    else if (*element1 < *element2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
