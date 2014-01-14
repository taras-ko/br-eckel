#include <iostream>
using namespace std;

class A {
	int _private;
public:
	int _public;
protected:
	int _protected;
};

int main()
{
	A a;
	a._public = 1;
	a._private = 1;
	a._protected = 1;
}
