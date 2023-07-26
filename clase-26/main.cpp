#include <iostream>
#include "hash.h"

using namespace std;

uint squareHashing(string key)
{
  int sum = 0;
  for (int i = 0; i < key.length(); i++)
  {
    sum += key[i] * key[i];
  }
  return sum;
}

uint residualHashing(string key)
{
  int sum = 0;
  for (int i = 0; i < key.length(); i++)
  {
    sum += key[i];
  }
  return sum % 5;
}

int main()
{
  HashTable<string, int> table(10, string(""), squareHashing);
  table.put("hello", 1);
  table.put("world", 2);
  table.put("foo", 3);
  table.put("bar", 4);
  cout << table.toString() << endl;
  return 0;
}