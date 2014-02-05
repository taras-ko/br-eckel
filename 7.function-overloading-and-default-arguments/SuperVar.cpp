#include <iostream>
using namespace std;

class SuperVar {
	union { // Anonymous union
		char c;
		int i;
		float f;
	};
public:
	enum Vartype {
#ifdef USE_CHAR
		character,
#endif
#ifdef USE_INT
		integer,
#endif
#ifdef USE_FLOAT
		floating_point
#endif
	}; // Define one
	SuperVar(char ch) : c(ch) {}
	SuperVar(int ii) : i(ii) {}
	SuperVar(float ff) : f(ff) {}
	void print(enum Vartype vtype)
	{
		switch (vtype) {
#ifdef USE_CHAR
			case character:
				cout << "character: " << c << endl;
				break;
#endif
#ifdef USE_INT
			case integer:
				cout << "integer: " << i << endl;
				break;
#endif
#ifdef USE_FLOAT
			case floating_point:
				cout << "float: " << f << endl;
				break;
#endif
		}
	}
};

int main()
{
	SuperVar A('c'), B(12), C(1.44F);

	A.print(SuperVar::character);
	B.print(SuperVar::integer);
	C.print(SuperVar::floating_point);
} ///:~
