#include "standardhashfunction.h"

int StandardHashFunction::getHashCode(QString &string, int divider) const
{
    int result = 0;
    for (int i = 0; i <= string.length(); i++)
    {
        result += string[i].toLatin1();
        result %= divider;
    }
    return result;
}
