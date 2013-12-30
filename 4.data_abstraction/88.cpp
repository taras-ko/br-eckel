#include <fstream>
#include <iostream>
#include <string>

#include <stdlib.h>

#include <Stack.h>
#include <require.h>

using namespace std;

int main(int argc, char* argv[])
{
	Stack doubles;
	doubles.initialize();
	double dbl;
	const unsigned short stack_size = 25;

	for (int i = 0; i < stack_size; i++)
		doubles.push(new double(drand48()));

	// Pop the lines from the Stack and print them:
	double* pdbl;
	while((pdbl = (double *) doubles.pop()) != 0) {
		cout << *pdbl << endl;
		delete pdbl;
	}
	doubles.cleanup();
} ///:~

