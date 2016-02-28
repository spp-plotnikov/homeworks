#pragma once
#include "list.h"
#include "listnode.h"

class PointerList : public List
{
public:
    PointerList();
    void add(int);
    bool isFound(int) const;
    void remove(int);
    void print() const;
    ~PointerList();
private:
    ListNode *first;
};
