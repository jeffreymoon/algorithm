#include "Makingchange.h"
#include <stdio.h>

void GetChange(int Price, int Pay, int CoinUnits[], int Change[], int Size)
{
  int ChangeAmount = Pay - Price;
  for (int i = 0; i < Size; i++) {
    Change[i] = CountCoins(ChangeAmount, CoinUnits[i]);
    ChangeAmount = ChangeAmount - (CoinUnits[i] * Change[i]);
  }
}

int CountCoins(int Amount, int CoinUnit)
{
  int CoinCount = 0;
  int CurrentAmount = Amount;

  while(CurrentAmount >= CoinUnit) {
    CoinCount++;
    CurrentAmount = CurrentAmount - CoinUnit;
  }
  return CoinCount;
}

void PrintChange(int CoinUnits[], int Change[], int Size)
{
  for (int i = 0; i < Size; i++) {
    printf("%8d$: %d ea\n", CoinUnits[i], Change[i]);
  }
}