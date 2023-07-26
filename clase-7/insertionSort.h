#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <vector>
#include "swap.h"

using namespace std;

void insertionSort(vector<int> &v)
{
  for (int i = 1; i < v.size(); i++)
  {
    for (int j = i - 1; j >= 0; j--)
    {
      if (v[j] > v[j + 1])
      {
        swap(v, j, j + 1);
      }
      else
      {
        continue;
      }
    }
  }
}

#endif