#pragma once
#include "list.h"

class ListsComparator
{
public:
    /*!
     * \brief compares two lists by length
     * \return 1, if  the first list is bigger than second,
     * 0, if the lists are equal by length
     * -1, if second list is bigger than first
     */
    static int compare(List *list1, List *list2);
};
