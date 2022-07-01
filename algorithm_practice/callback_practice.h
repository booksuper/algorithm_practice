#pragma once
#include <iostream>
#include <vector>

using namespace std;

int add(int a, int b);

void Add(int(*in_f)(int, int), int a, int b,int & res);