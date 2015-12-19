#pragma once

struct String;
__declspec(dllexport)  String* getSubstring(String*, int, int);
__declspec(dllexport)  String* createString(const char*);
__declspec(dllexport)  String* clone(String*);
__declspec(dllexport)  void concatForChar(String*, const char*);
__declspec(dllexport)  void concat(String*, String*);
__declspec(dllexport)  void printTheString(String*);
__declspec(dllexport)  void deleteString(String*);
__declspec(dllexport)  bool isTheSame(String*, String*);
__declspec(dllexport)  bool isEmpty(String*);
__declspec(dllexport)  int lengthOfString(String*);

//  Be careful after using this function! Don't forget to use "delete[]" to delete char*
__declspec(dllexport)  char* stringToChar(String*);
