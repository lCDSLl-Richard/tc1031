#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

template <typename T>
class Node
{
public:
  T value;
  Node<T> *next;

  Node();
  Node(T val);
  Node(T val, Node<T> *);
};

template <typename T>
Node<T>::Node()
{
  value = 0;
  next = nullptr;
}

template <typename T>
Node<T>::Node(T val)
{
  value = val;
  next = nullptr;
}

template <typename T>
Node<T>::Node(T val, Node *n)
{
  value = val;
  next = n;
}

template <typename T>
class Queue
{
public:
  int size;
  Node<T> *head;
  Node<T> *tail;

  Queue();

  T pop();
  T first();
  void push(T val);
  bool isEmpty();
};

template <typename T>
Queue<T>::Queue()
{
  size = 0;
  head = nullptr;
}

template <typename T>
bool Queue<T>::isEmpty()
{
  return head == nullptr;
}

template <typename T>
void Queue<T>::push(T val)
{
  if (isEmpty())
  {
    head = new Node(val);
    tail = head;
    return;
  }
  Node<T> *insert = new Node(val);
  tail->next = insert;
  tail = insert;
}

template <typename T>
T Queue<T>::pop()
{
  if (isEmpty())
    return NULL;

  Node<T> *del = head;
  head = head->next;
  T store = del->value;
  delete del;
  return store;
}

template <typename T>
T Queue<T>::first()
{
  return head->value;
}

#endif