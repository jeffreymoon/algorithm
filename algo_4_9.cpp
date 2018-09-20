#include <vector>
#include <limits>
using namespace std;

const int MIN = numeric_limits<int>::min();

int inefficientMaxSum(const vector<int>& A)
{
  int N = A.size();
  int ret = MIN;
  for (int i = 0; i < N; ++i) {
    for (int j = i; j < N; ++j) {
      int sum = 0;
      for (int k = i; k <= j; ++k) {
        sum += A[k];
      }
      ret = max(ret, sum);
    }
  }
  return ret;
}

int betterMaxSum(const vector<int>& A)
{
  int N = A.size();
  int ret = MIN;

  for (int i = 0; i < N; ++i) {
    int sum = 0;
    for (int j = i; j < N; ++j) {
      sum += A[j];
      ret = max(ret, sum);
    }
  }
  return ret;
}