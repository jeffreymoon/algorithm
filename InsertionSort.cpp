#include "common.h"

template<typename data, typename compare>
void insertion_sort(data* base, size_t n, compare com)
{
  for(size_t i = 1; i < n; i++) {
    for(size_t j = i; j > 0; j--) {
      if(com(base[j-1], base[j]) > 0) {
        swap(base[j-1], base[j]);
      } else {
        break;
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
  insertion_sort(base, 10, CompareByNum);
  cout << "Sorting by number" << endl;
  ViewMembers(base, 10);
  insertion_sort(base, 10, CompareByName);
  cout << "Sorting by name" << endl;
  ViewMembers(base, 10);
  RemoveMembers(base, 10);

  clock_t st, et;

  MakeRandomMembers(base, MAX_DATA);
  cout << "Performance test 1 data size: " << MAX_DATA << endl;
  st = clock();
  insertion_sort(base, MAX_DATA, CompareByName);
  et = clock();
  cout << "Execution time: " << et-st << endl;
  RemoveMembers(base, MAX_DATA);

  MakeRandomMembers(base, MAX_DATA/10);
  cout <<"Performance test 2nd data size: " << MAX_DATA/10 << endl;
  st = clock();
  MakeRandomMembers(base, MAX_DATA/10);
  insertion_sort(base, MAX_DATA/10, CompareByName);
  et = clock();
  cout << "Execution time: " << et-st << endl;
  RemoveMembers(base, MAX_DATA/100);
  return 0;
}