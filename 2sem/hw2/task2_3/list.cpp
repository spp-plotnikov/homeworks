#include "list.h"


bool List::operator >(const List &list) const
{
    return (this->length() > list.length());
}


bool List::operator <(const List &list) const
{
    return (list > *this);
}
