#include <iostream>
#include <string>
#include "../../lib/include/debug.h"

using namespace std;
class X {
	string name;
public:
//	X(const X& rx) : name("copy of " + rx.name) { print(); }
	X(const string& _name) : name(_name) {}
	void print() const { cout << name << endl; }
};

#if 0
void f(X& rx)
{
	rx.print();
	X x = rx;
	x.print();
}
#endif

void f(X& x)
{
	X _x = x;
}

int main()
{
	X x("x");
	X& rx = x;
	d(X x2 = rx);
	x2.print();
}
