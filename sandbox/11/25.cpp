#include <iostream>
using namespace std;

class X {
public:
	double d, *pd;
	static const int sz = 5;
	int arr[sz];
	X() : d(0.0), pd(&d) {}
	void print() const {
		cout << *pd << endl;
	}
	static void static_print() { cout << sz << endl; }
	void (X::*pfun)();
};

void print() {}
int main()
{
	X x, *px;
	px = &x;

	void (X::*pfun)() const = &X::print;

	int (X::*p)[X::sz] = &X::arr;

	for (int i = 0; i < X::sz; i++)
		cout << x.*p[i] << ' ';
		;
	cout << endl;

	(x.*pfun)();
}
