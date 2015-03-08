#include <iostream>
using namespace std;

class X {
	double d, *pd;
public:
	X() : d(0.0), pd(&d) {}
	void print() const {
		cout << *pd << endl;
	}
	void (X::*pfun)() const;
};

void print() {}
int main()
{
	X x, *px;

	x.pfun = &X::print;
	px = &x;

	void (X::*pf)() const = &X::print;

	(x.*pf)();
}
