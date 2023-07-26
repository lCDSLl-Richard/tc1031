#include <iostream>

using namespace std;

template <typename T>

void print(T x)
{
  cout << x << endl;
}

int main()
{
  print("Hello world");
  print(2);
  print(true);
}