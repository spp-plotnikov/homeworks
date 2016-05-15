#pragma once


/*!
 * \author © Sasha Plotnikov Production, Ltd.
 * \brief SharedPointer counts the number of references to the allocated memory
 * \details it's an analogue of std::shared_ptr
 */
template <typename Type>
class SharedPointer
{
public:
    /// \brief creates a pointer to the object or null pointer
    SharedPointer(Type *thisObject = nullptr);
    /// \brief creates a copy of this pointer
    SharedPointer(const SharedPointer &pointer);
    /// \brief gives access to fields and methods of the object
    Type* operator->();
    /// \returns the ref to object
    Type& operator*();
    /// \brief the assignment operator
    SharedPointer& operator=(const SharedPointer &pointer);
    /// \returns number of copies
    int getCount();
    ~SharedPointer();

    /// \brief if you'll try to dereference a null pointer you'll catch this exception
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
