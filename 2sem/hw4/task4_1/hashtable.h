#pragma once

#include <QList>
#include "nonexistentelementexception.h"

/*!
 * \author © Sasha Plotnikov Production, Ltd.
 * \brief The template for working with the hash table
 * \details The resolution of collisions by the method of chains (lists)
 */

template <typename Type>
class HashTable
{
public:
    HashTable();
    void add(Type &newElement);
    void remove(Type &target);
    bool find(Type &target);
    void statistics();    ///<  prints load factor, the number of cells, max len of the list, etc.
    void setHashFunction(function<int (Type *value, int size)> hasFunction);
    ~HashTable();

private:
    /// \brief This method rebuilds the table if its size was changed
    void updateTable(int newSizeOfTable);

    int size = 2048;    ///<    The starting value
    int fullness = 0;
    QList **table = new QList*[size];
};


//--------------------------------------------------------------


template <typename Type>
HashTable<Type>::HashTable()
{
    for (int i = 0; i < size; i++)
    {
        table[i] = NULL;
    }
}


template <typename Type>
void HashTable<Type>::add(Type &newElement)
{
    const int hashCode = hashFunction(newElement, size);

    if (!table[hashCode])
    {
        table[hashCode] = new QList;
    }
    if (!table[hashCode]->contains(newElement))
    {
        fullness++;
        table[hashCode]->append(newElement);
    }

    if (fullness > 0.9 * size)
    {
        updateTable(2 * size);
    }
}


template <typename Type>
void HashTable<Type>::remove(Type &target)
{
    if (!find(target))
    {
        throw NonexistentElementException();
    }

    const int hashCode = hashFunction(target, size);
    table[hashCode]->removeOne(target);
    fullness--;

    if (fullness < 0.3 * size && size > 2048)
    {
        updateTable(size / 2);
    }
}


template <typename Type>
bool HashTable<Type>::find(Type &target)
{
    const int hashCode = hashFunction(target, size);
    if (table[hashCode] && table[hashCode]->contains(target))
        return true;
    return false;
}


template <typename Type>
void HashTable<Type>::statistics()
{

}


template <typename Type>
void HashTable<Type>::setHashFunction(function<int (Type *, int)> hasFunction)
{

}


template <typename Type>
HashTable<Type>::~HashTable()
{
    for (int i = 0; i < size; i++)
        if (table[i])
            delete table[i];
    delete []table;
}


//--------------------------------------------------------------


template <typename Type>
void HashTable<Type>::updateTable(int newSizeOfTable)
{
    const int obsoleteSize = size;
    size = newSizeOfTable;
    QList **newTable = new QList*[size];
    for (int i = 0; i < size; i++)
    {
        newTable[i] = NULL;
    }

    QList **tempTable = table;  //  hah hah hah the pun as the name for the variable :-)
    table = newTable;
    for (int i = 0; i < obsoleteSize; i++)
    {
        if (tempTable[i])
        {
            while (!tempTable[i]->empty())
            {
                add(tempTable[i]->back());
                tempTable[i]->removeOne(tempTable[i]->back());
            }
        }
    }

    for (int i = 0; i < obsoleteSize; i++)
    {
        if (tempTable[i])
        {
            delete tempTable[i];
        }
    }
    delete []tempTable;
}
