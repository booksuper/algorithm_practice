#include "callback_practice.h"

int add(int a, int b)
{
	return a+b;
}

void Add(int(*in_f)(int, int), int a, int b,int & res)
{
	res = in_f(a, b);
}
