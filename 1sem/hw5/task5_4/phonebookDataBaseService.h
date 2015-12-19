#pragma once

using namespace std;

struct Entry
{
	long long number;
	char name[1024];
	Entry *next;
};


struct DataBase
{
	Entry *first;
};


__declspec(dllexport)  void addNewEntry(DataBase*, long long, char*);
__declspec(dllexport)  DataBase createDataBase();
__declspec(dllexport)  void saveDataBase(DataBase*, char*, int);
__declspec(dllexport)  void scanTheDataBase(DataBase*, char*, int&);
__declspec(dllexport)  void removeDataBase(DataBase&);

/*
Information for users of this function:
This function searches a number by name and a name by number.
Therefore, when the function is called in place of the missing argument should write -1.
*/
__declspec(dllexport)  void findEntry(DataBase*, long long, const char*);