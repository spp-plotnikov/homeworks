#pragma once

#include "hashfunction.h"


/// \brief advanced hash function for strings using primes
class OptimalHashFunction : public HashFunction
{
public:
    int getHashCode(QString &string, int divider) const;
};
