#pragma once
#pragma warning(disable:4996)
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
using std::ostream;
using std::endl;
#include <cstdio>
#include <conio.h>
#include <windows.h>
enum keydata
{
  NO_DEFINED, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, ESC
};

class ehglobal
{
public:
  static void clrscr();
  static void timeflow(int millisecond);
  static int getnum();
  static string getstr();
  static int getkey();
private:
  ehglobal(void) { }
  ~ehglobal(void) { }
};