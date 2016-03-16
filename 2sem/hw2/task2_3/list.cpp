#include "list.h"
#include <iostream>


bool List::operator >(const List &list) const
{
    return (this->length() > list.length());
}


bool List::operator <(const List &list) const
{
    return (list > *this);
}
