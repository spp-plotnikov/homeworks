#pragma once

#include "avltree.h"


template <typename Type>
class Set
{
public:
    Set();
    void add();
    bool remove();
    bool find() const;
    void setIntersection();
    void setUnion();
    ~Set();
};

TODO: tests (and for AVLTree)
TODO: doxygen comments
