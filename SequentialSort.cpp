#include "common.h"

template<typename data, typename compare>
void sequential_sort(data* base, size_t n, compare com)
{
  for(size_t i = 0; i < n; i++) {
    for(size_t j = i+1; j < n; j++) {
      if(com(base[i], base[j]) > 0) {
        swap(base[i], base[j]);
      }
    }
  }
}

//#define MAX_DATA 1000
const int MAX_DATA = 1000;
int main()
{
  Member* base[MAX_DATA];
  MakeRandomMembers(base, 10);
  cout << "Before sorting" << endl;
  ViewMembers(base, 10);
  sequential_sort(base, 10, CompareByNum);
  cout << "Sorting by number" << endl;
  ViewMembers(base, 10);
  sequential_sort(base, 10, CompareByName);
  cout << "Sorting by name" << endl;
  ViewMembers(base, 10);
  RemoveMembers(base, 10);

  clock_t st, et;

  MakeRandomMembers(base, MAX_DATA);
  cout << "Performance test 1 data size: " << MAX_DATA << endl;
  st = clock();
  sequential_sort(base, MAX_DATA, CompareByName);
  et = clock();
  cout << "Execution time: " << et-st << endl;
  RemoveMembers(base, MAX_DATA);

  MakeRandomMembers(base, MAX_DATA/10);
  cout <<"Performance test 2nd data size: " << MAX_DATA/10 << endl;
  st = clock();
  MakeRandomMembers(base, MAX_DATA/10);
  sequential_sort(base, MAX_DATA/10, CompareByName);
  et = clock();
  cout << "Execution time: " << et-st << endl;
  RemoveMembers(base, MAX_DATA/100);
  return 0;
}