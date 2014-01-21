#include <iostream>
using namespace std;

class A;
class C {
public:
	void printx(A *);
};

class B;
class A {
	int x, y, z;
public:
	A();
	friend class B;
	friend void C::printx(A *);
};

A::A(): x(1), y(2), z(3) {}

class B {
public:
	void printx(A *);
	void printy(A *);
};

void B::printx(A *pA)
{
	cout << pA->x << endl;
}

void B::printy(A *pA)
{
	cout << pA->y << endl;
}

void C::printx(A *pA)
{
	cout << pA->x << endl;
}

int main()
{
	A a;
	B b;
	C c;

	b.printx(&a);
	b.printy(&a);
	c.printx(&a);

}
