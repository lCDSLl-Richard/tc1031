#include <iostream>

using namespace std;

int binSearch(int arr[], int max, int dato)
{
  int min = 0;
  while (min <= max)
  {
    int mid = (min + max) / 2;

    if (dato == arr[mid])
      return mid;

    else if (dato < arr[mid])
      max = mid - 1;

    else
      min = mid + 1;
  }
  return -1;
}

int main()
{
  int const size = 10;
  int arr[size] = {0, 1, 4, 5, 6, 7, 7, 9, 10, 25};

  cout << binSearch(arr, size, 5) << endl;

  return 0;
}