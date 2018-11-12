#include <iostream>
using namespace std;
long long Factorial(int n)
{
  if(n <= 0) {
    return 0;
  }
  if(n == 1) {
    return 1;
  }
  return n*Factorial(n-1);
}

int main()
{
  for(int i = 0; i <= 10; i++) {
    cout << i << "!= " << Factorial(i) << endl;
  }
  return 0;
}