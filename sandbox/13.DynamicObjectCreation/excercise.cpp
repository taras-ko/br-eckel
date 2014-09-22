#include <iostream>
#include <PStash.h>
#include <Stack.h>
#include <vector>

class Counted {
	static int count;
	int id;
	void print(const char *fun) const {
		std::cout << fun <<"(): id = " << id << std::endl;
	}
public:
	void echo() const { std::cout << "echo from " << id << std::endl; }
	Counted(): id(count++) {
		print("Counted");
	}
	~Counted() {
		print("~Counted");
	}
};

int Counted::count = 0;

int main()
{
	using namespace std;

// Ex 13.10
// Ex. 13.9
#if 0
	void *pobj = (void *) new Counted;

	delete pobj;
#endif

// Ex. 13.8
#if 0
	Counted *carr = new Counted[10];

	delete carr;
#endif

// Excercise 13.7
#if 0
	Stack stack;

	for (int i = 0; i < 10; i++)
		stack.push(new Counted);

	Counted *c_ptr;
	while (c_ptr = (Counted *) stack.pop()) {
		c_ptr->echo();
		delete c_ptr;
	}
#endif

}
