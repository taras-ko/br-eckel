#include <iostream>
#include <string.h>

char *strcppdup(char *s)
{
	char *dup = new char[strlen(s) + 1];

	char *src = s;
	char *dest = dup;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';

	return dup;
}

using namespace std;
int main()
{
	char s[] = "Hello world!";
	char *s1 = strcppdup(s);
	char *s2 = strcppdup(s1);

	cout << static_cast<void *>(s1) << endl <<
		static_cast<void *>(s2) << endl;

	delete[] s1, s2;
}
