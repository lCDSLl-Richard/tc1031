#include <iostream>

using namespace std;

int binSearch(int arr[], int max, int min, int dato)
{
  int mid = (min + max) / 2;

  if (dato == arr[mid])
    return mid;

  else if (dato < arr[mid])
    return (binSearch(arr, (mid - 1), min, dato));

  else
    return (binSearch(arr, max, (mid + 1), dato));

  return -1;
}

int main()
{
  int const size = 10;
  int arr[size] = {0, 1, 4, 5, 6, 7, 7, 9, 10, 25};

  cout << binSearch(arr, size, 0, 25) << endl;

  return 0;
}