#include <iostream>
#include "consoleprinter.h"

using namespace std;

void ConsolePrinter::print(int **array, const int size)
{
    printTheArray(array, size, cout);
}
