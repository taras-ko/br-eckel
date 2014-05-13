//: C07:Mem.h
#ifndef MEM_H
#define MEM_H
typedef unsigned char byte;
class Mem {
	byte *oldmem;
	byte *mem;
	int size;
	void ensureMinSize(int minSize);
public:
	Mem(int sz = 0);
	~Mem();
	int msize();
	byte *pointer();
	byte *pointer(int minSize);
	bool moved();
};
#endif // MEM_H ///:~
