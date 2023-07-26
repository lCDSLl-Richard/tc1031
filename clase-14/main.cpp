#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
  Stack<float> stack;

  stack.push(9.123);
  stack.push(2.123);
  stack.pop();
  stack.push(4.123);
  stack.push(7.123);
  stack.pop();
  stack.pop();

  cout << stack.top();
}