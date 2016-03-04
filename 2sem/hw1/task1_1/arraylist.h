#pragma once
#include "list.h"

class ArrayList : public List
{
public:
    ArrayList() {}
    void add(int newElement);
    bool isFound(int target) const;
    void remove(int target);
    void print() const;
    ~ArrayList();
private:
    void resize();

    int size = 32;
    int quantity = 0;
    int *array = new int[size + 1];

};
