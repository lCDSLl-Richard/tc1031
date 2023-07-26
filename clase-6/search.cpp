#include <iostream>

using namespace std;

int search(int arr[], int size, int data)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == data)
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  int const size = 10;
  int arr[size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  cout << search(arr, size, 6) << endl;

  return 0;
}