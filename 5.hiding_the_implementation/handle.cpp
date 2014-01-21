//: C05:Handle.cpp {O}
// Handle implementation
#include "handle.h"
#include "../lib/include/require.h"
// Define Handle's implementation:
struct Handle::Cheshire {
	int i;
};

void Handle::initialize() {
	smile = new Cheshire;
	smile->i = 0;
}
void Handle::cleanup() {
	delete smile;
}

int Handle::read() {
	return smile->i;
}

void Handle::change(int x) {
	smile->i = x;
} ///:~

int main()
{
	Handle u;
	u.initialize();
	u.read();
	u.change(1);
	u.cleanup();
}
