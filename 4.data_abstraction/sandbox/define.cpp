#include <stdio.h>

int main()
{
#ifdef DEFINITION
	printf("%s\n", "print this");
#else
	printf("%s\n", "print that");
#endif
}
