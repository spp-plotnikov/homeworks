#include "listscomparator.h"

int ListsComparator::compare(List *list1, List *list2)
{
    if (*list1 > *list2)
    {
        return 1;
    }
    else if (*list1 < *list2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
