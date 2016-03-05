#pragma once
#include "printer.h"

class ConsolePrinter : public Printer
{
public:
    void print(int **array, const int size);
};
