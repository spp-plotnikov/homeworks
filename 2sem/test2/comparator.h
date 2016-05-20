#pragma once

template <typename Type>
class Comparator
{
public:
    /*!
     * \brief compares two elements (for example lists by length, the numbers in absolute value, etc.)
     * \warning You must use the data types that can be compared
     * \return 1, if the first element is bigger than second,
     * 0, if the elements are equal by size (length)
     * -1, if second elenent is bigger than first
     */
    virtual int compare(const Type &element1, const Type &element2) const;
};
