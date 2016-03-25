#include <QCoreApplication>
#include <iostream>
#include "priorityqueue.h"
#include "deletingfromemptyqueue.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PriorityQueue<char> *example = new PriorityQueue<char>();
    example->enqueue('f',3);
    example->enqueue('h',2);
    example->enqueue('d',1);
    example->enqueue('i',2);
    while (!example->isEmpty())
    {
        cout << example->dequeue();
    }
    try
    {
        example->dequeue();
    }
    catch (DeletingFromEmptyQueue &)
    {
        cout << "ololo" << endl;
    }

    delete example;
    return a.exec();
}
