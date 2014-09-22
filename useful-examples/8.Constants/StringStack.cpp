//: C08:StringStack.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Using static const to create a 
// compile-time constant inside a class
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

class MyString {
	string s;
public:
	MyString(string _s = "") : s(_s) {}
	void print() const {
		cout << s << endl;
	}
};

class StringStack {
  static const int size = 100;
  const MyString *stack[size];
  int index;
public:
  StringStack();
  void push(const MyString *s);
  const MyString *pop();
};

StringStack::StringStack() : index(0) {
  memset(stack, 0, size * sizeof(MyString *));
}

void StringStack::push(const MyString *s) {
  if (index < size)
    stack[index++] = s;
}

const MyString *StringStack::pop() {
  if (index > 0) {
    const MyString *rv = stack[--index];
    stack[index] = NULL;
    return rv;
  }
  return NULL;
}

MyString iceCream[] = {
  MyString("pralines & cream"),
  MyString("fudge ripple"),
  MyString("jamocha almond fudge"),
  MyString("wild mountain blackberry"),
  MyString("raspberry sorbet"),
  MyString("lemon swirl"),
  MyString("rocky road"),
  MyString("deep chocolate fudge")
};

const int iCsz = sizeof iceCream / sizeof *iceCream;

int main() {
  StringStack ss;
  for (int i = 0; i < iCsz; i++)
    ss.push(&iceCream[i]);

  const MyString *cp;
  while((cp = ss.pop()) != NULL)
	  cp->print();
}
