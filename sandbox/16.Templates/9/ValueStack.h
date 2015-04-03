//: C16:ValueStack.h
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Holding objects by value in a Stack
#ifndef VALUESTACK_H
#define VALUESTACK_H
#include "require.h"

#include <iostream>
#include <cstring>
/* 9
Modify ValueStack.h so that it dynamically expands as
you push( ) more objects and it runs out of space. Change
ValueStackTest.cpp to test the new functionality.
*/

template<typename T, int ssize = 100>
class Stack {
  int size;
  // Default constructor performs object
  // initialization for each element in array:
  T **stack;
  int top;
public:
  Stack() : top(0), size(ssize) {
    stack = new T*[size];
    T *block = new T[size];
    for (int i = 0; i < size; i++) {
      stack[i] = &block[i];
    }
  }
  ~Stack() {
//    for (int i = 0; i < size; i++)
 //     delete stack[i];

    delete []stack;
  }
  void expand(int increase_by);
  // Copy-constructor copies object into array:
  void push(const T& x) {
    if (top == size) {
      std::cout << "Expanding Stack by " << size << std::endl;
      expand(size);
    }
    *stack[top++] = x; // (3) SelfCounter assigned 1 to 0; (5) SelfCounter destroyed: 0
  }
  T peek() const { return stack[top]; }
  // Object still exists when you pop it; 
  // it just isn't available anymore:
  T pop() {
    require(top > 0, "Too many pop()s");
    return stack[--top];
  }
};

template <typename T, int ssize>
void Stack<T, ssize>::expand(int increase_by)
{
  int old_size = size;

  size += increase_by;
  T **expanded_stack = new T*[size];
  for (int i = 0; i < old_size; i++) {
    expanded_stack[i] = stack[i];
  }
  for (int i = old_size; i < size; i++) {
    expanded_stack[i] = new T;
  }
  delete []stack;

  stack = expanded_stack;
}
#endif // VALUESTACK_H ///:~
