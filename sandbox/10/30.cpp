#include <iostream>
using namespace std;

struct Int {
	int var;
	Int(int _var = 0) {}
};

void f()
{
	Int arr[10];
	for (int i = 0; i < 10; i++)
		cout << arr[i].var << " ";
	cout << endl;
}

int main() {
	f();
}
