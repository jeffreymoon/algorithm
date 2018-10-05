#include "common.h"

template<typename data, typename compare>
void selection_sort(data* base, size_t n, compare com)
{
  for(size_t i = 0; i < n; i++) {
    size_t min = i;
    for(size_t j = i + 1; j < n; j++) {
      if(com(base[min], base[j]) > 0) {
        min = j;
      }
    }
    swap(base[i], base[min]);
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
  selection_sort(base, 10, CompareByNum);
  cout << "Sorting by number" << endl;
  ViewMembers(base, 10);
  selection_sort(base, 10, CompareByName);
  cout << "Sorting by name" << endl;
  ViewMembers(base, 10);
  RemoveMembers(base, 10);

  clock_t st, et;

  MakeRandomMembers(base, MAX_DATA);
  cout << "Performance test 1 data size: " << MAX_DATA << endl;
  st = clock();
  selection_sort(base, MAX_DATA, CompareByName);
  et = clock();
  cout << "Execution time: " << et-st << endl;
  RemoveMembers(base, MAX_DATA);

  MakeRandomMembers(base, MAX_DATA/10);
  cout <<"Performance test 2nd data size: " << MAX_DATA/10 << endl;
  st = clock();
  MakeRandomMembers(base, MAX_DATA/10);
  selection_sort(base, MAX_DATA/10, CompareByName);
  et = clock();
  cout << "Execution time: " << et-st << endl;
  RemoveMembers(base, MAX_DATA/100);
  return 0;
}