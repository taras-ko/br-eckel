#include <fstream>
#include <iostream>
#include <string>

#include <Stack.h>
#include <require.h>

using namespace std;

int main(int argc, char* argv[])
{
#if 0
	requireArgs(argc, 1);
	ifstream in(argv[1]);
	assure(in, argv[1]);
#endif

	string one("One");
	string two("Two");
	string three("Three");
	string *lines[3] = { &one, &two, &three };

	Stack textlines((void **) &lines, sizeof(lines));
	string line;

#if 0
	while(getline(in, line))
		textlines.push(new string(line));
#endif
	string *s;

	while((s = (string *) textlines.pop()) != 0 ) {
		cout << *s << endl;
//		delete s;
	}

	delete &one;
}
