
#include <fstream>
#include <iostream>
#include <string>

#include <PStash.h>
#include <require.h>

using namespace std;
int main()
{
	PStash intStash;

	for (int i = 0; i < 100; i++)
		intStash.add(new int(i));

	for (int i = 0; i < intStash.size(); i++)
		cout << *(int*)intStash[i] << endl;

	for (int k = 0; k < intStash.size(); k++)
		delete (int *)intStash.remove(k);

	ifstream in("stash-test.cpp");
	assure(in, "stash-test.cpp");

	PStash stringStash;
	string line;
	while (getline(in, line))
		stringStash.add(new string(line));

	for (int u = 0; stringStash[u]; u++)
		cout << "stringStash[" << u << "] = "
			<< *(string *)stringStash[u] << endl;

	for (int v = 0; v < stringStash.size(); v++)
		delete (string*)stringStash.remove(v);
} ///:~
