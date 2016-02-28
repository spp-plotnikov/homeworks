#pragma once

template <typename Type>
class Stack
{
public:
    Stack() {}
    virtual void push(const Type) = 0;
    virtual Type pop() = 0;
    virtual Type viewTheTop() const = 0;
    virtual ~Stack() {}
};
