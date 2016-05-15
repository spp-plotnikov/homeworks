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

    class NullPointerException {};
private:
    /// \brief deletes this copy of pointer
    deleteCopy();

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


template <typename Type>
Type* SharedPointer<Type>::operator ->()
{
    return object;
}


template <typename Type>
Type& SharedPointer<Type>::operator *()
{
    if (!object)
    {
        throw NullPointerException();
    }
    return *object;
}


template <typename Type>
SharedPointer<Type> &SharedPointer<Type>::operator =(const SharedPointer &pointer)
{
    deleteCopy();

    object = pointer.object;
    count = pointer.count;
    if (count)
    {
        (*count)++;
    }
    return *this;
}


template <typename Type>
int SharedPointer<Type>::getCount()
{
    if (count)
    {
        return *count;
    }
    else
    {
        return 0;
    }
}


template <typename Type>
SharedPointer<Type>::~SharedPointer()
{
    deleteCopy();
}


//----------------------------------


template <typename Type>
void SharedPointer<Type>::deleteCopy()
{
    if (count)
    {
        (*count)--;

        if (*count == 0)
        {
            delete count;
            delete object;
        }

        count = nullptr;
        object = nullptr;
    }
}


TODO: 1) comments 2) tests
