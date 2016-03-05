#include "fileprinter.h"

FilePrinter::FilePrinter(char *theFileName)
{
    fout.open(theFileName);
}


void FilePrinter::print(int **array, const int size)
{
    printTheArray(array, size, fout);
}


FilePrinter::~FilePrinter()
{
    fout.close();
}
