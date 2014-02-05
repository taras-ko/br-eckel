#include "Mem.h"
#include <cstring>

using namespace std;

Mem::Mem(int sz)
	: mem(NULL), oldmem(NULL), size(0)
{
	ensureMinSize(sz);
}

Mem::~Mem() { delete []mem; }

int Mem::msize() { return size; }

void Mem::ensureMinSize(int minSize)
{
	if (size < minSize) {
		oldmem = mem;
		byte *newmem = new byte[minSize];
		memset(newmem + size, 0, minSize - size);
		memcpy(newmem, mem, size);
		delete []mem;
		mem = newmem;
		size = minSize;
	}
}

byte *Mem::pointer() {
	oldmem = mem;
	return mem;
}

byte *Mem::pointer(int minSize)
{
	ensureMinSize(minSize);
	return mem;
}

bool Mem::moved()
{
	return oldmem != mem;
}
