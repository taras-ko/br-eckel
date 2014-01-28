#include <fstream>
#include <iostream>
#include <string>

#include <Stack.h>
#include <require.h>

using namespace std;

int main(int argc, char* argv[])
{
	requireArgs(argc, 1);
	ifstream in(argv[1]);
	assure(in, argv[1]);
	Stack textlines;
	string line;

	while(getline(in, line))
		textlines.push(new string(line));

	string *s;

	while((s = (string *) textlines.pop()) != 0 ) {
		cout << *s << endl;
		delete s;
	}
}
