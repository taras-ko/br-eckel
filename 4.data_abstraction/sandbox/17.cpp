#include<iostream>
using namespace std;
int main()
{
	int *pint = new int;
	long *plong = new long;
	char *carr = new char[100];
	float *farr = new float[100];

	cout <<
		pint << endl <<
		plong << endl <<
		static_cast<void *>(carr) << endl <<
		farr << endl;

	delete pint, plong;
	delete[] carr, farr;
}
