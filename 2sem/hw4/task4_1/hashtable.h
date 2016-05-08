#pragma once

#include <QList>
#include <iostream>
#include "hashfunction.h"

using namespace std;

/*!
 * \author © Sasha Plotnikov Production, Ltd.
 * \brief The template for working with the hash table
 * \details The resolution of collisions by the method of chains (lists)
 */

template <typename Type>
class HashTable
{
public:
    HashTable(HashFunction &userHashFunction);
    void add(Type &newElement);
    bool remove(Type &target);  ///<    \returns false if the table doesn't contains this value
    bool find(Type &target);
    void statistics() const;    ///<  prints load factor, the number of cells, max len of the list, etc.
    void setHashFunction(HashFunction &userHashFunction);
    ~HashTable();

private:
    /// \brief This method rebuilds the table if its size was changed
    void updateTable(int newSizeOfTable);
    /// \brief the wrapper function for code readability
    int hashFunction(Type &value, const int divisor);

    int size = 2048;    ///<    The starting value
    int fullness = 0;
    HashFunction *hashFunc = nullptr;    ///<    a pointer to the User hash function
    QList<Type> **table = new QList<Type>*[size];
};


//--------------------------------------------------------------


template <typename Type>
HashTable<Type>::HashTable(HashFunction &userHashFunction)
{
    for (int i = 0; i < size; i++)
    {
        table[i] = nullptr;
    }
    hashFunc = &userHashFunction;
}


template <typename Type>
void HashTable<Type>::add(Type &newElement)
{
    const int hashCode = hashFunction(newElement, size);

    if (!table[hashCode])
    {
        table[hashCode] = new QList<Type>;
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
bool HashTable<Type>::remove(Type &target)
{
    if (!find(target))
    {
        return false;
    }

    const int hashCode = hashFunction(target, size);
    table[hashCode]->removeOne(target);
    fullness--;

    if (fullness < 0.3 * size && size > 2048)
    {
        updateTable(size / 2);
    }
    return true;
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
void HashTable<Type>::statistics() const
{
    int maxLength = 0;
    int emptyCells = 0;
    int conflicts = 0;

    for (int i = 0; i < size; i++)
    {
        if (!table[i] || table[i]->length() == 0)
        {
            emptyCells++;
        }
        else
        {
            if (table[i]->length() > maxLength)
                maxLength = table[i]->length();
            if (table[i]->length() > 1)
                conflicts++;
        }
    }

    cout << endl << "------------------------------------------" << endl;
    cout << "The quantity of different values: " << fullness << endl;
    cout << "Table size: " << size << endl;
    double loadFactor = static_cast < double > ( fullness ) / size;
    cout << "Load factor: ~ " << int(loadFactor * 100) << "%" << endl;
    cout << "Quantity of empty cells in the table: " << emptyCells << endl;
    cout << "Quantity of conflicts: " << conflicts << endl;
    double  averageLength = static_cast < double > ( fullness ) / (size - emptyCells);
    if (averageLength != averageLength)
        averageLength = 0;  //  In case of occurrence of NaN
    cout << "The average chain length: " << averageLength << endl;
    cout << "The maximal chain length: " << maxLength << endl;
    cout << "------------------------------------------" << endl;
}


template <typename Type>
void HashTable<Type>::setHashFunction(HashFunction &userHashFunction)
{
    hashFunc = &userHashFunction;
    updateTable(size);
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
int HashTable<Type>::hashFunction(Type &value, const int divisor)
{
    return hashFunc->getHashCode(value, divisor);
}


template <typename Type>
void HashTable<Type>::updateTable(int newSizeOfTable)
{
    const int obsoleteSize = size;
    size = newSizeOfTable;

    QList<Type> **tempTable = table;  //  hah hah hah the pun as the name for the variable :-)
    table = new QList<Type>*[size];
    for (int i = 0; i < size; i++)
    {
        table[i] = NULL;
    }
    fullness = 0;

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
