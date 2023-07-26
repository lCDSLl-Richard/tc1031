#include <iostream>

typedef unsigned int uint;

using namespace std;

long potencia(int base, int n)
{
  if (n == 0)
    return 1;

  return base * potencia(base, n - 1);
}

void digits(uint n)
{
  if (n >= 0 && n < 10)
    cout << n << " ";
  else
  {
    digits(n / 10);
    cout << n % 10 << " ";
  }
}

uint factorial(uint n)
{
  return n <= 1 ? 1 : n * factorial(n - 1);
}

int allSum(int n)
{
  if (n == 0)
    return 0;

  return n == 1 ? 1 : n + allSum(n - 1);
}

int pascalTriangle(int r, int c)
{
  if (c == 0 || r == c)
    return 1;
  else
    return pascalTriangle(r - 1, c - 1) + pascalTriangle(r - 1, c);
}