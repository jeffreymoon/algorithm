#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int is_prime(int n)
{
  for(int i = 2; i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int is_prime2(int n)
{
  int sqrn;
  sqrn = (int)sqrt(n);
  for (int i = 2; i <= sqrn; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main(int ac, char** av)
{
  if (ac < 2) {
    cout << "Usage : prime [int]" << endl;
    return 0;
  }

  int n = atoi(av[1]);
  if (n < 2) {
    cout << "Error : n must be great then 1" << endl;
    return 0;
  }

  int *parray;

  parray = new int [n+1];
  if (parray == nullptr) {
    cout << "Error : memory allocation failed" << endl;
    return 0;
  }

  memset(parray, 0, sizeof(int)*(n+1));

  int i, j;

  for (i = 2; i <= n; i++) {
    if (parray[i] == 1) {
      continue;
    }
    j = i;
    while ((j += i) <= n) {
      parray[j] = 1;
    }
  }

  for (i = 2; i <= n; i++) {
    if (parray[i] == 0) {
      cout << i << endl;
    }
  }
  cout << endl;

  delete[] parray;

  // cout << is_prime2(4) << endl;
  return 0;
}