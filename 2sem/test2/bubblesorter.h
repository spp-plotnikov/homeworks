#pragma once

#include <QList>
#include <cstdlib>
#include "comparator.h"
#include "intsinabsolutevaluecomparator.h"


/*!
 * \brief Interface of the sorter (bubble sort)
 * \author © Sasha Plotnikov Production, Ltd.
 */
template <typename Type>
class BubbleSorter
{
public:
    /// \brief sorts objects in the list using comparator
    static void sort(QList<Type> &list, const Comparator<Type> &comparator);
};


//-------------------------------------------------


template <typename Type>
void BubbleSorter<Type>::sort(QList<Type> &list, const Comparator<Type> &comparator)
{
    for (int i = 0; i < list.size() - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < list.size() - i - 1; j++)
        {
            if (comparator.compare(list[j], list[j + 1]) == 1)
            {
                std::swap(list[j], list[j + 1]);
                swapped = true;
            }
        }

        if(!swapped)
        {
           break;
        }
    }
}
