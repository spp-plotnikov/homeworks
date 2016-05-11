#pragma once

#include "../../../2sem/hw1/task1_1/list.h"
#include "../../../2sem/hw1/task1_1/arraylist.h"
#include "../../../2sem/hw1/task1_1/pointerlist.h"


class UniqueList : public List
{
    // exception here
};


class ArrayUniqueList : public UniqueList, public ArrayList
{
public:
    ArrayUniqueList() : ArrayList() {}
    void add(int newValue);
    void remove(int target);
};


class PointerUniqueList : public UniqueList, public PointerList
{
public:
    PointerUniqueList() : PointerList() {}
    void add(int newValue);
    void remove(int target);
};
