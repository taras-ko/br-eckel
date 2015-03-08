#include <iostream>

class X {
	static const char alphabet[];
	static char symbols[];
public:
	static void print(const char arr[] = symbols) {
		for (int i = 0; i < sizeof arr / sizeof *arr; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
	static void print_a() { print(alphabet); }
};

const char X::alphabet[] = {
	'a', 'b', 'c', 'd', 'e', 'f', 'g'
};

char X::symbols[] = {
	'h', 'e', 'l', 'l', 'o'
};
int main()
{
	X::print();
	X::print_a();
}
