
//: C04:CLibTest.cpp
//{L} CLib
// Test the C-like library
#include <fstream>
#include <iostream>
#include <string>

#include <Stash.h>
#include <require.h>

using namespace std;
int main()
{
	// Define variables at the beginning
	// of the block, as in C:
	Stash intStash(sizeof(int));
	for (int i = 0; i < 100; i++)
		intStash.add(&i);

	for (int i = 0; i < intStash.count(); i++)
		cout << *(int*)intStash.fetch(i) << endl;

	const int bufsize = 80;
	// Holds 80-character strings:
	Stash stringStash(sizeof(char) * bufsize, 100);
	ifstream in("Makefile");
	assure(in, " Makefile");

	string line;
	while (getline(in, line))
		stringStash.add(line.c_str());

	int k = 0;
	char *cp;
	while((cp = (char*) stringStash.fetch(k++)) != 0)
		cout << cp << endl;

} ///:~
