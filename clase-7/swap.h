#ifndef SWAP_H
#define SWAP_H

#include <vector>

using namespace std;

void swap(vector<int> &v, int a, int b)
{
  v[a] += v[b];
  v[b] = v[a] - v[b];
  v[a] = v[a] - v[b];
}

#endif