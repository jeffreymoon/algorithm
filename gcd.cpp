#include <iostream>
using namespace std;

int get_gcd(int u, int v)
{
  int t;
  while(v) {
    t = u % v;
    u = v;
    v = t;
  }
  return u;
}

int main()
{
  cout << get_gcd(230, 30) << endl;
  return 0;
}