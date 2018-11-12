#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int* sequentailsearch(int* base, size_t n, int value)
{
  for(size_t s = 0; s < n; ++s) {
    if(base[s] == value) {
      return base+s;
    }
  }
  return 0;
}

int* binarysearch(int* base, size_t n, int value)
{
  if(n <= 0) {
    return 0;
  }
  int gap = base[n/2] - value;
  if(gap == 0) {
    return base + n/2;
  }
  if(gap>0) {
    return binarysearch(base, n/2, value);
  }
  return binarysearch(base+n/2 + 1, n-n/2-1, value);
}

int main()
{
  int arr[100000];
  srand((unsigned)time(0));

  for(int i = 0; i < 100000; i++) {
    arr[i] = i*5 + rand()%5;
  }

  clock_t st, et;
  st = clock();
  for(int tc = 0; tc < 10000; tc++) {
    int index = rand()%100;
    sequentailsearch(arr, 100, arr[index]);
  }
  et = clock();
  cout << "Sequentail 10000 times in 100ea data: " << et-st << endl;

  st = clock();
  for(int tc=0; tc<10000; tc++) {
    int index = rand()%100000;
    sequentailsearch(arr, 100000, arr[index]);
  }
  et = clock();
  cout << "Sequentail 10000 times in 100000ea data: " << et-st << endl;

  st = clock();
  for(int tc = 0; tc < 10000; tc++) {
    int index = rand()%100;
    binarysearch(arr, 100, arr[index]);
  } 
  et = clock();
  cout << "Binary 10000 times in 100ea data: " << et-st << endl;

  st=clock();
  for(int tc = 0; tc < 10000; tc++) {
    int index = rand()%100000;
    binarysearch(arr, 100000, arr[index]);
  }
  et = clock();
  cout << "Binary 10000 times in 100000ea data: " << et-st << endl;
  return 0;
}