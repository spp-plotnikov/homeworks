#pragma once

#include <QString>

/// \brief advanced hash function for strings using primes
int optimalHashFunction(QString &string, int divider);

/// \brief simple hash function for strings sums the characters
int standardHashFunction(QString &string, int divider);
