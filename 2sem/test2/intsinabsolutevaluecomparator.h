#pragma once

#include <math.h>
#include "comparator.h"


/*!
 * \brief compares two integers in absolute value
 * \returns similarly as a parent-class Comparator
 */
template <typename Type>
class IntsInAbsoluteValueComparator : public Comparator
{
    static_assert(
            std::is_same<signed char, Type>::value ||
            std::is_same<short int, Type>::value ||
            std::is_same<int, Type>::value ||
            std::is_same<long int, Type>::value ||
            std::is_same<long long int, Type>::value,
            "The type must be a integer!"
        );
public:
    int compare(const Type &element1, const Type &element2) const;
};


//-----------------------------------------


template <typename Type>
int IntsInAbsoluteValueComparator<type>::compare(const type &element1, const type &element2) const
{
    if (abs(element1) > abs(element2))
    {
        return 1;
    }
    else if (abs(element1) < abs(element2))
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
