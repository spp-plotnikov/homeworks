#pragma once

class List
{
public:
    List() {}
    virtual void add(int newValue) = 0;
    virtual bool isFound(int target) const = 0;
    virtual void remove(int target) = 0;
    virtual void print() const = 0;
    virtual ~List() {}
};
