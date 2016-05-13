#pragma once

#include "../../../2sem/hw1/task1_1/list.h"
#include "../../../2sem/hw1/task1_1/arraylist.h"
#include "../../../2sem/hw1/task1_1/pointerlist.h"


/*!
 * \author © Sasha Plotnikov Production, Ltd.
 * \brief The UniqueList does not allow adding the same value
 * \details inherits from List, uses its functionality
 */
class UniqueList : public List
{
public:
    /// Exception will thrown when you try to add the existing value
    class ElementAlreadyExistsException {};

    /// Exception will thrown when you attempt to remove the non-existent element
    class AttemptToRemoveTheNonExistentElementException {};
};



/*!
 * \brief The ArrayUniqueList class inherits from ArrayList and UniqueList
 * the functionality is the same as the parents functionality
 * \details You can use a large potential of inheritance:
 * ArrayList *list1 = new ArrayUniqueList();
 * UniqueList *list2 = new ArrayUniqueList();
 */
class ArrayUniqueList : public UniqueList, public ArrayList
{
public:
    ArrayUniqueList() : ArrayList() {}
    void add(int newValue);
    void remove(int target);
    bool isFound(int target) const;
    void print() const;
};



/*!
 * \brief The PointerUniqueList class inherits from PointerList and UniqueList
 * the functionality is the same as the parents functionality
 * \details You can use a large potential of inheritance:
 * PointerList *list1 = new PointerUniqueList();
 * UniqueList *list2 = new PointerUniqueList();
 */
class PointerUniqueList : public PointerList, public UniqueList
{
public:
    PointerUniqueList() : PointerList() {}
    void add(int newValue);
    void remove(int target);
    bool isFound(int target) const;
    void print() const;
};
