#pragma once

template <typename Type>
class Stack
{
public:
    virtual void push(const Type value) = 0;
    virtual Type pop() = 0;
    virtual Type viewTheTop() const = 0;
    virtual ~Stack() {}
};
