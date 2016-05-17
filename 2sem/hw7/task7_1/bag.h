#pragma once

#include "../../../2sem/hw5/task5_2/set.h"

/*!
 *   \brief  Interface of the module for working with the multiset
 *   \author © Sasha Plotnikov Production, Ltd.
 */
class Bag
{
public:
    /// \param value will be added to bag
    void add(int value);
    /// \returns  true if value was successfully removed
    bool remove(int value);
    /// \returns true if the multiset contains the value
    bool find(int value);
    /// \returns the number of such values
    int getCount(int value);
    ~Bag();

private:
    /// \brief This is a helper class to store the value and the number of such values
    class Pair
    {
    public:
        Pair(int thisValue) : value(thisValue) {}

        bool operator >(const Pair &pair) const;
        bool operator <(const Pair &pair) const;

        int value = 0;
        int count = 0;
    };

    Set<int> *set = new Set<int>();
};
