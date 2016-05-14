#pragma once


template <typename Type>
class SharedPointer
{
public:
    SharedPointer(Type *thisObject = nullptr);
    SharedPointer(const SharedPointer &pointer);
    Type* operator->();
    Type& operator*();
    SharedPointer& operator=(const SharedPointer &pointer);
    int getCount();
    ~SharedPointer();
private:
    Type *object = nullptr;
    int *count = nullptr;    ///<    number of copies
};


//------------------------------------------------------


template <typename Type>
SharedPointer<Type>::SharedPointer(Type *thisObject)
{
    object = thisObject;
    if (object)
    {
        count = new int(1);
    }
}


template <typename Type>
SharedPointer<Type>::SharedPointer(const SharedPointer<Type> &pointer)
{
    object = pointer.object;
    count = pointer.count;
    if (count)
    {
        (*count)++;
    }
}

TODO: 1) comments 2) tests
