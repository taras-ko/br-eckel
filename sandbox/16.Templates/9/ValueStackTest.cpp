//: C16:ValueStackTest.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
//{L} SelfCounter
#include "ValueStack.h"
#include "SelfCounter.h"
#include <iostream>
using namespace std;

int main() {
#if 0
  Stack<SelfCounter> sc;
  for(int i = 0; i < 10; i++)
    sc.push(SelfCounter());
#else
  Stack<SelfCounter, 1> sc; // (1) SelfCounter created: 0
  sc.push(SelfCounter()); // (2) SelfCounter created: 1
  sc.push(SelfCounter()); // (2) SelfCounter created: 1
  sc.push(SelfCounter()); // (2) SelfCounter created: 1
  sc.push(SelfCounter()); // (2) SelfCounter created: 1
  sc.push(SelfCounter()); // (2) SelfCounter created: 1
#endif
#if 0
  // OK to peek(), result is a temporary:
  cout << sc.peek() << endl;
  for(int k = 0; k < 10; k++)
    cout << sc.pop() << endl;
#endif
}
// (6) SelfCounter destroyed: 1
// (7) SelfCounter destroyed: 0
