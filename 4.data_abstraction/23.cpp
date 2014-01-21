#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

#include <Stack.h>
#include <Stash.h>
#include <require.h>

using namespace std;
struct Stacksh {
	void initialize();
	void push(char *);
	void *pop();
	friend int main(int, char *);
private:
	int bufsize;
	int i;
	Stack stack;
	Stash *pstash;
}

Stacksh::initialize()
{
	i = 0;
	bufsize = 80;
	stack.initialize();
}

Stacksh::push(string& line)
{
	if (i == 0) {
		pstash = new Stash;
		pstash->initialize(sizeof(char) * bufsize);
	};

	pstash->add(line.c_str());
	i++;

	if (i == 5) {
		stack.push(pstash);
		i = 0;
	};
}


int main(int argc, char *argv[])
{
	requireArgs(argc, 1);
	ifstream in(argv[1]);
	assert(in);

	string line;
	Stacksh stacksh;

	char *str;

	while (getline(in, line))
		stacksh.push(line);

	if (stacksh.pstash->count() > 0)
		stack.push(pstash);

	stack.reverse();

	while ((pstash = (Stash *) stack.pop()) != 0) {
		for (int i = 0; (str = (char*) pstash->fetch(i)) != 0; i++)
			cout << str << endl;
		pstash->cleanup();
	}

	stack.cleanup();
}
