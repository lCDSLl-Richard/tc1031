#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
  Queue<int> q;

  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);

  cout << q.pop() << " " << q.pop() << " " << q.pop() << " " << q.pop() << endl;
}