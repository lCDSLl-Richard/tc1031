#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <vector>
#include "swap.h"

using namespace std;

void selectionSort(vector<int> &v)
{
  for (int i = 0; i < v.size() - 1; i++)
  {
    int menor = i;

    for (int j = i + 1; j < v.size(); j++)
    {
      menor = v[menor] < v[j] ? menor : j;
    }
    if (menor != i)
    {
      swap(v, menor, i);
    }
  }
}

#endif