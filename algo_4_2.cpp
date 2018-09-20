#include <vector>
using namespace std;

int majority2(const vector<int>& A)
{
  int N = A.size();
  vector<int> count(101,0);
  for (int i = 0; i < N; ++i) {
    count[A[i]]++;
  }

  int majority = 0;
  for (int i = 1; i <= 100; ++i) {
    if (count[i] > count[majority]) {
      majority = i;
    }
  }
  return majority;
}
