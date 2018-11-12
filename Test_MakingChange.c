#include "Makingchange.h"
#include <stdio.h>
#include <stdlib.h>

int Compare(const void* a, const void* b)
{
  int _a = *(int*)a;
  int _b = *(int*)b;

  if( _a < _b) {
    return 1;
  } else {
    return -1;
  }
}

int main(void)
{
  int Pay = 0;
  int Price = 0;
  int UnitCount = 0;
  int* CoinUnits = NULL;
  int* Change = NULL;

  printf("Enter kinds of coin : ");
  scanf("%d", &UnitCount);

  CoinUnits = (int*) malloc(sizeof(int) * UnitCount);
  Change = (int*) malloc(sizeof(int) * UnitCount);

  for (int i = 0; i < UnitCount; i++) {
    printf("Enter [%d] th of coin unit: ", i);
    scanf("%d", &CoinUnits[i]);
  }

  qsort(CoinUnits, UnitCount, sizeof(int), Compare);

  printf("Enter price of goods: ");
  scanf("%d", &Price);

  printf("How much the guest paid? : ");
  scanf("%d", &Pay);

  GetChange(Price, Pay, CoinUnits, Change, UnitCount);
  PrintChange(CoinUnits, Change, UnitCount);
  return 0;
}