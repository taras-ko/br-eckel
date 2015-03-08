#include <iostream>

using namespace std;

class Str {
	string s;
public:
	Str(const string& _s = "") : s(_s) {}
	void print() const { cout << s; }
	bool is_end() const { return s == ""; }
};

class S {
	static const Str sarr[];
	static Str sarr2[];
public:
	static void print(const Str arr[] = sarr) {
		for (int i = 0; !arr[i].is_end(); i++)
			arr[i].print();
		std::cout << std::endl;
	}
	static void print_2() { print(sarr2); }
};

const Str S::sarr[] = {
	Str("Hello, "), Str("World!"), Str()
};

Str S::sarr2[] = {
	Str("This is "), Str("non const arr!"), Str()
};

int main()
{
	S::print();
	S::print_2();
}
