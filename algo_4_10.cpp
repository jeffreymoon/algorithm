#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int MIN = numeric_limits<int>::min();

int fastMaxSum(const vector<int>& A, int lo, int hi)
{
  if (lo == hi) {
    return A[lo];
  }
  int mid = (lo + hi) / 2;
  int left = MIN;
  int right = MIN;
  int sum = 0;

  for (int i = mid; i >= lo; --i) {
    sum += A[i];
    left = max(left, sum);
  }
  sum = 0;
  for (int j = mid+1; j <= hi; ++j) {
    sum += A[j];
    right = max(right, sum);
  }

  int single = max(fastMaxSum(A, lo, mid),
                   fastMaxSum(A, mid+1, hi));
  return max(left + right, single);
}

int main()
{
  vector<int> v = {-7, 4, -3, 6, 3, -8, 3, 4};
  cout << fastMaxSum(v, 0, 7) << endl;
  return 0;
}