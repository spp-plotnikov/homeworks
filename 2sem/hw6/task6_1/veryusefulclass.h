#pragma once

#include <iostream>

using namespace std;


class VeryUsefulClass
{
public:
    VeryUsefulClass()
    {
        cout << "Very useful object was created :-)" << endl;
    }

    ~VeryUsefulClass()
    {
        cout << "Very useful object was deleted :-(" << endl;
    }
};


class VeryUsefulClassChild : public VeryUsefulClass
{
public:
    VeryUsefulClassChild()
    {
        cout << "Very useful object of child class was created :-)" << endl;
    }

    ~VeryUsefulClassChild()
    {
        cout << "Very useful object of child class was deleted :-(" << endl;
    }

    void toDivideByZero()
    {
        throw DivideByZeroException();
    }

    class DivideByZeroException
    {
    public:
        DivideByZeroException()
        {
            cout << "Exception was created!!!" << endl;
        }

        ~DivideByZeroException()
        {
            cout << "Exception was deleted." << endl;
        }
    };
};
