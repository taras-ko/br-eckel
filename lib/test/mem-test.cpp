#include <cstring>
#include <iostream>

#include <Mem.h>

using namespace std;

class MyString {
	Mem *buf;
public:
	MyString(char *str = "");
	~MyString();
	void concat(char *str);
	void print(ostream& os);
};

MyString::MyString(char *str)
{
	if (!*str) {
		buf = NULL;
		return;
	}

	buf = new Mem(strlen(str) + 1);
	strcpy((char *)buf->pointer(), str);
}

void MyString::concat(char *str)
{
	if (!buf)
		buf = new Mem;
	strcat((char *) buf->pointer(buf->msize() + strlen(str) + 1), str);
}

void MyString::print(ostream& os)
{
	if (!buf)
		return;
	os << buf->pointer() << endl;
}

MyString::~MyString() { delete buf; }

int main()
{
	Mem mem;
	cout << mem.moved() << endl;
	mem.pointer(1);
	cout << mem.moved() << endl;

	MyString s("My test string");
	s.print(cout);
	s.concat(" some additional stuff");
	s.print(cout);
	MyString s2;
	s2.concat("Using default constructor");
	s2.print(cout);
} ///:~
