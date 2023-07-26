#ifndef STACK_H
#define STACK_H

using namespace std;

template <typename T>
class Stack
{
private:
  T data[10];
  int tope;

public:
  Stack();

  void push(T val);
  T top();
  void pop();
  bool isEmpty();
  bool isFull();
};

template <typename T>
Stack<T>::Stack()
{
  int tope = -1;
}

template <typename T>
void Stack<T>::push(T val)
{
  if (!isFull())
  {
    tope++;
    data[tope] = val;
  }
}

template <typename T>
T Stack<T>::top()
{
  if (!isEmpty())
  {
    return data[tope];
  }

  return NULL;
}

template <typename T>
void Stack<T>::pop()
{
  if (!isEmpty())
  {
    tope--;
  }
}

template <typename T>
bool Stack<T>::isEmpty()
{
  return tope == -1 ? true : false;
}

template <typename T>
bool Stack<T>::isFull()
{
  return tope == 9 ? true : false;
}

#endif