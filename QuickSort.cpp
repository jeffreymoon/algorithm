#include <iostream>
#include <ctime>
#include "common.h"
using namespace std;

template <typename data, typename compare>
void quick_sort(data* base, size_t n, compare com)
{
  if(n <= 1) {
    return ;
  }
  int pivot = 0;
  if((com(base[0], base[n-1]) > 0) && // {
    (com(base[0], base[n/2]) > 0)) {
      if(com(base[n/2], base[n-1]) > 0) {
        pivot = n/2;
      } else {
        pivot = n-1;
      }
    //}
  } else {
    if(com(base[n/2], base[n-1]) > 0) {
      pivot = n-1;
    } else {
      if(com(base[n/2], base[0]) > 0) {
        pivot = n/2;
      }
    }
  }
  swap(base[0], base[pivot]);
  size_t big = 0;
  size_t small = n;
  while(big < small) {
    for(big++; big < n; big++) {
      if(com(base[0], base[big]) < 0) {
        break;
      }
    }
    for(small--; small > 0; small--) {
      if(com(base[0], base[small]) > 0) {
        break;
      }
    }
    if(big < small) {
      swap(base[big], base[small]);
    }
    swap(base[0], base[small]);
    quick_sort(base, small, com);
    quick_sort(base+big, n-big, com);
  }
}

#define MAX_DATA 1000
int main()
{
  Member* base[MAX_DATA];
  MakeRandomMembers(base, 10);
  cout << "before " << endl;
  ViewMembers(base, 10);
  quick_sort(base, 10, CompareByNum);
  cout << "after by number " << endl;
  ViewMembers(base, 10);
  quick_sort(base, 10, CompareByName);
  cout << "after by name " << endl;
  ViewMembers(base, 10);
  RemoveMembers(base, 10);

  clock_t st, et;

  MakeRandomMembers(base, MAX_DATA);
  cout << "Test 1 count of data: " << MAX_DATA << endl;
  st = clock();
  quick_sort(base, MAX_DATA, CompareByName);
  et = clock();
  cout << "Execuation time: " << et - st << endl;
  RemoveMembers(base, MAX_DATA);

  MakeRandomMembers(base, MAX_DATA/10);
  cout << "Test 2 count of data: " << (MAX_DATA/10) << endl;
  st = clock();
  quick_sort(base, MAX_DATA/10, CompareByName);
  et = clock();
  cout << "Execuation time: " << et - st << endl;
  RemoveMembers(base, MAX_DATA/10);


}