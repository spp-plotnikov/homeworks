#pragma once

#include "../../../2sem/hw1/task1_1/list.h"
#include "../../../2sem/hw1/task1_1/arraylist.h"
#include "../../../2sem/hw1/task1_1/pointerlist.h"


class UniqueList : public List
{
public:
    class ElementAlreadyExistsException {};
    class AttemptToRemoveTheNonExistentElementException {};
};


class ArrayUniqueList : public UniqueList, public ArrayList
{
public:
    ArrayUniqueList() : ArrayList() {}
    void add(int newValue);
    void remove(int target);
    bool isFound(int target) const;
    void print() const;
};


class PointerUniqueList : public PointerList, public UniqueList
{
public:
    PointerUniqueList() : PointerList() {}
    void add(int newValue);
    void remove(int target);
    bool isFound(int target) const;
    void print() const;
};

comments and tests
