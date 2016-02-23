#pragma once

class List
{
public:
    List();
    virtual void add(int);
    virtual bool isFound(int) const;
    virtual void remove(int);
    virtual void print() const;
    virtual ~List();
};
