#include <assert.h>
#include <iostream>

using namespace std;

int GetSumAToB(int start, int end);

int main()
{
  assert(GetSumAToB(1, 10) == 55);
  assert(GetSumAToB(5, 10) == 45);
  cout << "Success" << endl;
  return 0;
}

int GetSumAToB(int start, int end)
{
  int sum = 0;
  for(int index = start; index<=end; ++index) {
    sum += index;
  }
  return sum;
}