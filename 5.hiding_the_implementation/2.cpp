#include <iostream>
#include <string>

using namespace std;

class Lib {
	string a, b, c;
public:
	friend void manipulator1(Lib *);
	friend void manipulator2(Lib *);
};

void manipulator1(Lib *obj)
{
	obj->a = "Hello";
	obj->b = ", I'm ";
	obj->c = "manipulator!";
}

void manipulator2(Lib *obj)
{
	cout << obj->a << obj->b << obj->c << endl;
}

int main()
{
	Lib x;

	manipulator1(&x);
	manipulator2(&x);
}
