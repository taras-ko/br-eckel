#include <iostream>
#include <string>

using namespace std;

class B;

class A {
	string msg;
public:
	A();
	void printout();
	void f(B *);
};

class B {
	string msg;
public:
	B();
	void printout();
	void f(A *);
};


A::A(): msg("This is class A") {}

void A::printout()
{
	cout << msg;
}
void A::f(B *pB)
{
	pB->printout();
}

B::B(): msg("This is class B") {}

void B::printout()
{
	cout << msg;
}
void B::f(A *pA)
{
	pA->printout();
}

int main()
{
	A a;
	B b;

	a.f(&b);
	b.f(&a);
}
