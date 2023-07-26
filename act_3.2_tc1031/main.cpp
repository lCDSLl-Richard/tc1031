#include <iostream>
#include "priority_queue.h"

using namespace std;

int main()
{
  Priority_queue<int> pq;

  cout << "Empty?: " << pq.empty() << endl;
  pq.push(1);
  cout << "Empty?: " << pq.empty() << endl;
  cout << pq.toString() << endl;
  pq.push(2);
  pq.push(7);
  pq.push(6);
  pq.push(5);
  pq.push(10);
  pq.push(8);
  pq.push(5);
  cout << pq.toString() << endl;
  cout << "Size: " << pq.size() << endl;
  cout << "Popped element: " << pq.pop() << endl;
  cout << pq.toString() << endl;
  cout << "Size: " << pq.size() << endl;
  cout << "Popped element: " << pq.pop() << endl;
  cout << pq.toString() << endl;
  cout << "Size: " << pq.size() << endl;
  cout << "Popped element: " << pq.pop() << endl;
  cout << pq.toString() << endl;
  cout << "Size: " << pq.size() << endl;
  cout << "Popped element: " << pq.pop() << endl;
  cout << pq.toString() << endl;
  cout << "Size: " << pq.size() << endl;
  cout << "Popped element: " << pq.pop() << endl;
  cout << pq.toString() << endl;
  cout << "Size: " << pq.size() << endl;
  cout << "Popped element: " << pq.pop() << endl;
  cout << "Final: ";
  cout << pq.toString() << endl;
}