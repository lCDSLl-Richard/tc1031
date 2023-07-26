#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <string>
#include <sstream>

using namespace std;

typedef unsigned int uint;

template <class T>
class Priority_queue
{
private:
  uint current;
  vector<T> data;
  void swap(uint, uint);

public:
  Priority_queue();
  ~Priority_queue();

  uint left(uint);
  uint right(uint);
  uint parent(uint);

  bool empty();
  uint size();

  void push(T);
  void resort(uint);
  T top();
  T pop();

  string toString();
};

template <class T>
Priority_queue<T>::Priority_queue()
{
  current = 0;
}

template <class T>
Priority_queue<T>::~Priority_queue()
{
  data.clear();
}

/**
 * Swap two elements in the data vector.
 *
 * @param i, position 1 to be swapped.
 * @param j, position 2 to be swapped.
 * @complexity O(1)
 */
template <class T>
void Priority_queue<T>::swap(uint i, uint j)
{
  T aux = data[i];
  data[i] = data[j];
  data[j] = aux;
}

/**
 * Obtains the left node of the current node.
 *
 * @param parent, the node whose left node is to be calculated.
 * @return left node index.
 * @complexity O(1)
 */
template <class T>
uint Priority_queue<T>::left(uint parent)
{
  return parent * 2 + 1;
}

/**
 * Obtains the right node of the current node.
 *
 * @param parent, the node whose right node is to be calculated.
 * @return right node index.
 * @complexity O(1)
 */
template <class T>
uint Priority_queue<T>::right(uint parent)
{
  return parent * 2 + 2;
}

/**
 * Obtains the parent node of the current node.
 *
 * @param child, the node whose parent node is to be calculated.
 * @return index of parent node.
 * @complexity O(1)
 */
template <class T>
uint Priority_queue<T>::parent(uint child)
{
  return (child - 1) / 2;
}

/**
 * Checks if the queue is empty.
 *
 * @return bool wether it is empty or not.
 * @complexity O(1)
 */
template <class T>
bool Priority_queue<T>::empty()
{
  return current == 0;
}

/**
 * Obtains the size of the queue.
 *
 * @return amount of elemnts in queue.
 * @complexity O(1)
 */
template <class T>
uint Priority_queue<T>::size()
{
  return data.size();
}

/**
 * Obtains the top element of the queue.
 *
 * @return most important element of the queue.
 * @complexity O(1)
 */
template <class T>
T Priority_queue<T>::top()
{
  if (empty())
    throw exception();
  return data[0];
}

/**
 * Inserts a new value to the queue in its correct location.
 *
 * @param val, value to be inserted.
 * @complexity O(log n)
 */
template <class T>
void Priority_queue<T>::push(T val)
{
  uint pos = current++;
  data.push_back(val);

  while (pos > 0 && val > data[parent(pos)])
  {
    swap(pos, parent(pos));
    pos = parent(pos);
  }
}

/**
 * Puts the current element in its correct location in the heap.
 *
 * @param curr, node to be sorted.
 * @complexity O(log n)
 */
template <class T>
void Priority_queue<T>::resort(uint curr)
{
  uint currLeft = left(curr);
  uint currRight = right(curr);
  uint aux = curr;

  if (currLeft < current && data[currLeft] > data[curr])
    curr = currLeft;

  if (currRight < current && data[currRight] > data[curr])
    curr = currRight;

  if (curr != aux)
  {
    swap(curr, aux);
    resort(aux);
  }
}

/**
 * Dequeues the most important element of the heap.
 *
 * @return dequeued element.
 * @complexity O(log n)
 */
template <class T>
T Priority_queue<T>::pop()
{
  if (empty())
    throw;
  T aux = top();
  swap(0, --current);
  data.pop_back();
  resort(0);
  return aux;
}

/**
 * Converts the queue to a string
 *
 * @return a string with the data in array format.
 * @complexity O(n)
 */
template <class T>
string Priority_queue<T>::toString()
{
  stringstream info;
  info << "[ ";
  for (auto i : data)
    info << i << ", ";
  info << "]";
  return info.str();
}

#endif
