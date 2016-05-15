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

    ~Vector();
};
