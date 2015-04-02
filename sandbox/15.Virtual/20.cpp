/* Write a class with one virtual function and one non-
virtual function. Inherit a new class, make an object of
this class, and upcast to a pointer of the base-class type.
Use the clock( ) function found in <ctime> (you’ll need
to look this up in your local C library guide) to measure
the difference between a virtual call and non-virtual call.
You’ll need to make multiple calls to each function inside
your timing loop in order to see the difference. */

#include <iostream>
#include <ctime>

class Base {
public:
  virtual void foo() const {}
  void bar() const {}

  void call_fun(std::string& fun_name, void (Base::*fun_ptr)(), int n_calls) const;

  void call_foo(int n_calls) {
    std::cout << "Calling vitrual ";
    call_fun("foo()", Base::foo, n_calls);
  }
  void call_bar(int n_calls) {
    std::cout << "Calling non vitrual ";
   // call_fun("foo()", Base::bar, n_calls);
  }
};

void Base::call_fun(std::string& fun_name, void (Base::*fun_ptr)(), int n_calls) const {
  clock_t t2, t1 = std::clock();

  std::cout << fun_name << std::endl;
  for (int i = 0; i < n_calls; i++) {
    //fun_ptr();
  }

  t2 = std::clock();

  std::cout << "Time lapsed for call for " << fun_name <<
    " is " << t2-t1 << std::endl;
}

class Derived : public Base {};

int main()
{

}
