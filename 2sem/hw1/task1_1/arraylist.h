#pragma once
#include "list.h"

class ArrayList : public List
{
public:
    ArrayList();
    void add(int);
    bool isFound(int) const;
    void remove(int);
    void print() const;
    ~ArrayList();
private:
    int size;
    int quantity;
    int *array;
private:
    void resize();
};
