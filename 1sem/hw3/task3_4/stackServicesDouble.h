#pragma once

struct StackOfDoubles
{
	double value;
	StackOfDoubles *next = nullptr;
};


__declspec(dllexport) void push(StackOfDoubles *&newNext, const double newValue);
__declspec(dllexport) double pop(StackOfDoubles *&newNext);
