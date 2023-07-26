#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>
#include "swap.h"
#include <iostream>

using namespace std;

int split(vector<int> &v, int start, int end)
{
  int pivot = v[start];
  int i = start + 1;

  for (int j = start + 1; j < end; j++)
  {
    if (v[j] < pivot)
    {
      swap(v, i, j);
      for (int i : v)
        cout << i << " ";
      cout << endl;
      i++;
    }
  }
  swap(v, start, i - 1);
  return i;
}

void quickSort(vector<int> &v, int start, int end)
{
  if (start < end)
  {
    int pivIndex = split(v, start, end);
    quickSort(v, start, pivIndex - 1);
    quickSort(v, pivIndex + 1, end);
  }
}

#endif