#ifndef FUNC_H
#define FUNC_H
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <conio.h>
using namespace std;
//int name = 0, age = 0, address = 0;
void put(char*,string);
void gotoxy(int, int);
int wherex();
int wherey();
// sumber: http://www.tutorialspoint.com/cplusplus/cpp_templates.htm
template <typename T>
inline T const& test (T const& a, T const& b) 
{ 
    return a < b ? 1:0; 
}
#endif

