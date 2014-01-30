#include <iostream>

using namespace std;

class Four {
public:
	void f();
	void f(int);
	void f(int, int);
	void f(int, int, int);
};

void Four::f()
{
	cout << "f()" << endl;
}

void Four::f(int i)
{
	cout << "f(int)" << endl;
}

void Four::f(int i, int i2)
{
	cout << "f(int, int)" << endl;
}

void Four::f(int i, int i2, int i3)
{
	cout << "f(int, int, int)" << endl;
}

class One {
public:
	void f(int i = 0, int i2 = 0, int i3 = 0);
};

void One::f(int i = 0, int i2 = 0, int i3 = 0)
{
	cout << "!" << endl;
}

class Two {
public:
	void f(int, int);
};

void Two::f(int, int i);
int main()
{
	Four four;

	four.f();
	four.f(1);
	four.f(1, 2);
	four.f(1, 2, 3);

	One one;

	one.f();

	Two two;

	two.f(1,2);
}
