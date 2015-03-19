//: C14:Combined.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Inheritance & composition
//
#include <iostream>

using namespace std;

class A {
  int i;
public:
  A(int ii) : i(ii) {}
  ~A() {}
  virtual void f() const { cout << "A::f()" << endl; }
};

class B {
  int i;
public:
  B(int ii) : i(ii) {}
  ~B() {}
  virtual void f() const { cout << "B::f()" << endl; }
};

class C : public B {
  A a;
public:
  C(int ii) : B(ii), a(ii) {}
  ~C() {} // Calls ~A() and ~B()
  virtual void f() const {  // Redefinition
    cout << "C::f()" << endl;
    a.f();
    B::f();
  }
};

int main() {
  C c(47);
  B *b = static_cast<B *>(&c);

  b->f();
} ///:~
