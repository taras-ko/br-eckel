#include <iostream>

using namespace std;
class D {
	double *pd;
public:
	D(const double d = 3.14) {
		pd = new double(d);
	}
	D(const D& rd) {
		pd = new double(*rd.pd);
	}
	~D() {
		cout << "*pd = " << *pd << endl;
		*pd = -1;
		delete pd;
	}
};

void f(D d) {}

int main()
{
	D d;
	f(d);
}
