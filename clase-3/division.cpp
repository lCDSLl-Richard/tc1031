#include <iostream>

using namespace std;

bool divisibility(int arr[], int tam)
{
  int min = arr[0];

  for (int i = 1; i < tam; i++)
    min = min < arr[i] ? min : arr[i];

  for (int i = 0; i < tam; i++)
    if (arr[i] % min != 0)
      return false;

  return true;
}

int main()
{

  const int TAM = 3;

  int entry[TAM] = {8, 12, 4};
  cout << (divisibility(entry, TAM) ? "True" : "False") << endl;
}
