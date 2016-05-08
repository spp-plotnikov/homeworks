#pragma once

#include <QString>


/// \brief parent class for the different hash functions
class HashFunction
{
public:
    virtual int getHashCode(QString &string, int divider) const = 0;
};
