#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include <iostream>
#include "swap.h"

using namespace std;

void printVector(const vector<int> &v)
{
  for (int i : v)
    cout << i << " ";
}

void merge(vector<int> &v, int start, int mid, int end)
{
  int size1 = mid - start + 1, size2 = end - mid;

  vector<int> A(size1);
  vector<int> B(size2);

  for (int i = 0; i < size1; i++)
  {
    A[i] = v[i + start];
  }

  for (int i = 0; i < size2; i++)
  {
    B[i] = v[i + mid + 1];
  }

  int i = 0, j = 0, k = start;

  while (i < size1 && j < size2)
  {
    if (A[i] <= B[j])
    {
      v[k] = A[i];
      i++;
    }
    else
    {
      v[k] = B[j];
      j++;
    }
    k++;
  }

  while (i < size1)
  {
    v[k] = A[i];
    i++;
    k++;
  }

  while (j < size2)
  {
    v[k] = B[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int> &v, int start, int end)
{
  if (start < end)
  {
    int mid = start + (end - start) / 2;
    mergeSort(v, start, mid);
    mergeSort(v, mid + 1, end);
    merge(v, start, mid, end);
  }
}

#endif