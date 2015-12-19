#pragma once


struct Stack
{
	char symbol;
	Stack *next;
};

__declspec(dllexport) void push(Stack *&next, const char symbol);
__declspec(dllexport) char pop(Stack *&newNext);
__declspec(dllexport) char viewTheTop(Stack *&signs);
