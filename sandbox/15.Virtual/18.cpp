#include <iostream>

/* Create a class that has a data member and a derived class that adds another data member.
 * Write a non-member function that takes an object of the base class by value and prints
 * out the size of that object using sizeof( ). In main( ) create an object of the derived class,
 * print out its size, and then call your function. Explain what happens. */

using namespace std;

class Base {
  int i;
public:
  Base(Base& b) {
    cout << "Base::Base(Base& b)\n";
  }
  Base& operator=(const Base& rv) {
    cout << "Base::operator=(const Base& rv)\n";
    i = rv.i;
    return *this;
  }
  Base() { cout << "Base::Base()\n"; }
  ~Base() { cout << "Base::~Base()\n"; }
};

class Derived : public Base {
  float f;
public:
  Derived() { cout << "Derived::Derived()\n"; }
  ~Derived() { cout << "Derived::~Derived()\n"; }
};

void mySize(Base b)
{
  cout << "mySize == " << sizeof(b) << endl;
}

int main()
{
  Base b;
  Derived d;

  cout << "sizeof b == " << sizeof(b) << endl;
  cout << "sizeof d == " << sizeof(d) << endl;

  mySize(b);
  mySize(d);
}
