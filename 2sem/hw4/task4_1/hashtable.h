#pragma once

/*!
 * \author © Sasha Plotnikov Production, Ltd.
 * \brief the template for working with the hash table
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
};
