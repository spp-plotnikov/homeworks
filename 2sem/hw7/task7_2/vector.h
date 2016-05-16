#pragma once


/*!
 * \author © Sasha Plotnikov Production, Ltd.
 * \brief This is a template for working with vectors
 * \details You can add, subtract, scalar multiply, etc.
 * \param Type is the data type of the vector
 * \param dimension is the quantity of coordinates of the vector
 */
template <typename Type, int dimension>
class Vector
{
public:
    /// \brief creates a null vector
    Vector();
    /// \brief creates a copy of other vector
    Vector(const Vector &otherVector);
    /// \returns true if this vector is null vector
    bool isNull() const;
    /// \brief subtracts another vector
    Vector& operator-(const Vector &otherVector);
    /// \brief adds other vector
    Vector& operator+(const Vector &otherVector);
    /// \brief the assignment operator
    Vector& operator=(const Vector &otherVector);
    /// \brief scalar multiplication
    Type operator*(const Vector &otherVector);
    /// \returns the coordinate with that index (starts from zero)
    Type& operator[](int index);
    ~Vector();

    /// \brief if you'll try to get non-existent coordinate you'll catch this exception
    class OutOfRangeException {};
private:
    int *coordinates = new int[dimension + 1];
};


//------------------------------------------------


template <typename Type, int dimension>
Vector<Type, dimension>::Vector()
{
    for (int i = 0; i < dimension; i++)
    {
        coordinates[i] = 0;
    }
}


template <typename Type, int dimension>
Vector<Type, dimension>::Vector(const Vector<Type, dimension> &otherVector)
{
    for (int i = 0; i < dimension; i++)
    {
        coordinates[i] = otherVector[i];
    }
}


template <typename Type, int dimension>
bool Vector<Type, dimension>::isNull() const
{
    for (int i = 0; i < dimension; i++)
    {
        if (coordinates[i] != 0)
        {
            return false;
        }
    }
    return true;
}


template <typename Type, int dimension>
Vector<Type, dimension>& Vector<Type, dimension>::operator -(const Vector &otherVector)
{
    Vector<Type, dimension> result;
    for (int i = 0; i < dimension; i++)
    {
        result[i] = coordinates[i] - otherVector[i];
    }

    return result;
}


template <typename Type, int dimension>
Vector<Type, dimension>& Vector<Type, dimension>::operator +(const Vector &otherVector)
{
    Vector<Type, dimension> result;
    for (int i = 0; i < dimension; i++)
    {
        result[i] = coordinates[i] + otherVector[i];
    }

    return result;
}


template <typename Type, int dimension>
Vector<Type, dimension>& Vector<Type, dimension>::operator =(const Vector &otherVector)
{
    for (int i = 0; i < dimension; i++)
    {
        coordinates[i] = otherVector[i];
    }
    return *this;
}


template <typename Type, int dimension>
Type Vector<Type, dimension>::operator *(const Vector &otherVector)
{
    Type result = static_cast < Type > ( 0 );
    for (int i = 0; i < dimension; i++)
    {
        result += coordinates[i] * otherVector[i];
    }

    return result;
}


template <typename Type, int dimension>
Type& Vector<Type, dimension>::operator [](int index)
{
    if (index >= 0 && index < dimension)
    {
        return coordinates[i];
    }
    else
    {
        throw OutOfRangeException();
    }
}


template <typename Type, int dimension>
Vector<Type, dimension>::~Vector()
{
    delete []coordinates;
}