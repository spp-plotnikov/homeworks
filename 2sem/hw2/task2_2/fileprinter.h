#pragma once
#include <fstream>
#include "printer.h"

class FilePrinter : public Printer
{
public:
    FilePrinter(char *theFileName);
    void print(int **array, const int size);
    ~FilePrinter();
private:
    ofstream fout;
};
