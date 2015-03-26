#include <iostream>
#include <array>

using namespace std;

class Base {
public:
  Base() {
   // baz();
  }
  virtual void foo() const {
    cout << "Base::foo()" << endl;
  }
  virtual void bar() const {
    cout << "Base::bar()" << endl;
  }
  void baz() const {
    foo();
    bar();
  }
};

class Derived : public Base {
public:
  Derived() {
    baz();
  }
  virtual void foo() const {
    cout << "Derived::foo()" << endl;
  }
  virtual void bar() const {
    cout << "Derived::bar()" << endl;
  }
};

int main()
{
  array<Base *, 2> A { new Base, new Derived };

  for (const auto& elem : A) {
    elem->baz();
  }

  for (const auto& elem : A) {
    delete elem;
  }
}
