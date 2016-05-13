#pragma once

#include "hashfunction.h"


/// \brief simple hash function for strings sums the characters
class StandardHashFunction : public HashFunction
{
public:
    int getHashCode(QString &string, int divider) const;
};
