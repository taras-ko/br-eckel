#ifndef PSTASH_H
#define PSTASH_H
class PStash {
	int quantity;	// Number of storage blocks
	int next;		// Next empty block
	void **storage;
	void inflate(int increase);
public:
	PStash() : quantity(0), storage(0), next(0) {}
	~Stash();

	int add(void* element);
	void *operator[](int index) const;
	void *remove(int index);
	int count() const { return next; }
};
#endif // PSTASH_H

