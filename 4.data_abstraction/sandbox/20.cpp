#include <iostream>

using namespace std;

struct S1 {
};
struct S2 {
	int a, b;
};

struct S3 {
	int a, b;
	void f();
};

void S3::f()
{
	cout << "Hello";
}

int main()
{
	S1 s1;
	S2 s2;
	S3 s3;


	cout << sizeof(s1) << endl <<
		sizeof(s2) << endl <<
		sizeof(s3) << endl;
}
