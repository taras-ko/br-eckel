#include <iostream>

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
	int j;
public:
	Derived() { cout << "Derived::Derived()\n"; }
	~Derived() { cout << "Derived::~Derived()\n"; }
};

Base foo(Base b)
{
	cout << sizeof(b) << endl;
	return b;
}

int main()
{
	Derived d1;

	cout << sizeof(d1) << endl;

	Base b1(foo(d1));
}
