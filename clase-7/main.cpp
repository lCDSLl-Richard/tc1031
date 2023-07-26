#include <iostream>
#include "selectionSort.h"
#include "insertionSort.h"
#include "bubbleSort.h"
#include "mergeSort.h"
#include "quickSort.h"

using namespace std;

int main()
{
  vector<int> v{53, 53, 2, 3, 4, 9};

  quickSort(v, 0, v.size());

  for (int i : v)
    cout << i << endl;
}