#include "uniquelist.h"

void PointerUniqueList::add(int newValue)
{
    if (PointerList::isFound(newValue))
    {
        throw ElementAlreadyExistsException();
    }
    PointerList::add(newValue);
}


void PointerUniqueList::remove(int target)
{
    if (!PointerList::isFound(target))
    {
        throw AttemptToRemoveTheNonExistentElementException();
    }
    PointerList::remove(target);
}


bool PointerUniqueList::isFound(int target) const
{
    return PointerList::isFound(target);
}


void PointerUniqueList::print() const
{
    PointerList::print();
}


//-----------------------------


void ArrayUniqueList::add(int newValue)
{
    if (ArrayList::isFound(newValue))
    {
        throw ElementAlreadyExistsException();
    }
    ArrayList::add(newValue);
}


void ArrayUniqueList::remove(int target)
{
    if (!ArrayList::isFound(target))
    {
        throw AttemptToRemoveTheNonExistentElementException();
    }
    ArrayList::remove(target);
}


bool ArrayUniqueList::isFound(int target) const
{
    return ArrayList::isFound(target);
}


void ArrayUniqueList::print() const
{
    ArrayList::print();
}
