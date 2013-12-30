
//: C04:CLibTest.cpp
//{L} CLib
// Test the C-like library
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>

#include <Stash.h>

using namespace std;
int main()
{
	// Define variables at the beginning
	// of the block, as in C:
	Stash intStash, stringStash;
	int i;
	char *cp;
	ifstream in;
	string line;
	const int bufsize = 80;

	// Now remember to initialize the variables:
	intStash.initialize(sizeof(int));

	for (i = 0; i < 100; i++)
		intStash.add(&i);

	for (i = 0; i < intStash.count(); i++)
		cout << *(int*)intStash.fetch(i) << endl;

	// Holds 80-character strings:
	stringStash.initialize(sizeof(char) * bufsize);
	in.open("Makefile");
	assert(in);

	while (getline(in, line))
		stringStash.add(line.c_str());

	i = 0;
	while((cp = (char*) stringStash.fetch(i++)) != 0)
		cout << cp << endl;

	intStash.cleanup();
	stringStash.cleanup();
} ///:~
