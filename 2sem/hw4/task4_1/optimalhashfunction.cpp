#include "optimalhashfunction.h"

int OptimalHashFunction::getHashCode(QString &string, int divider) const
{
    unsigned long long result = 0;
    for (int i = 0; i <= string.length(); i += 2)
    {
        result += string[i].toLatin1() * 14 + (result % 23);
    }
    for (int i = string.length(); i >= 0; i--)
    {
        result += string[i].toLatin1() * 17 + (result % 35);
    }
    result += divider / 19 * string[0].toLatin1();
    result %= divider;
    return result;
}
