#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void Hanoi(string src, string use, string dest, int n)
{
  if(n <= 0) {
    return ;
  }
  Hanoi(src, dest, use, n-1);
  cout << "move " << src << " -> " << dest << endl;
  Hanoi(use, src, dest, n-1);
}

int main()
{
  clock_t st, et;
  st = clock();
  int n = 5;
  Hanoi("a", "b", "c", n);
  et = clock();
  cout << n << "ea spent time: " << et-st << endl;
  st = clock();
  n = 8;
  Hanoi("a", "b", "c", n);
  et = clock();
  cout << n << "ea spent time: " << et-st << endl;
  return 0;
}