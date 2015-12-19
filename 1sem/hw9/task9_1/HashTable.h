#pragma once
#include "string.h"

struct HashTable;

__declspec(dllexport)  HashTable* createTable();
__declspec(dllexport)  void addToHashTable(HashTable*, String*);
__declspec(dllexport)  void deleteTable(HashTable*);
__declspec(dllexport)  bool isPresentInTable(HashTable*, String*);