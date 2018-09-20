#include <iostream>
#include <vector>
using namespace std;

vector<int> factor(int n)
{
  if (n == 1) {
    return vector<int>(1, 1);
  }

  vector<int> ret;
  for (int div = 2; n > 1; ++div) {
    while(n % div == 0) {
      n /= div;
      ret.push_back(div);
    }
  }

  return ret;
}

int main()
{
  vector<int> ret = factor(4);
  for (auto i : ret) {
    cout << ret[i] << endl;
  }
  cout << "---" << endl;
  return 0;
}