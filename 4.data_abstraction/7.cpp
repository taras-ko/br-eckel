/* Make a Stash that holds doubles. Fill it with 25 double
 * values, then print them out to the console. */

#include  <stdlib.h>
#include <iostream>

#include <CLib.h>

using namespace std;
int main()
{
	CStash doubleStash;

	const unsigned short stash_count = 25;

	initialize(&doubleStash, stash_count * sizeof(double));

	for (int i = 0; i < stash_count; i++) {
		double number = drand48();
		add(&doubleStash, &number);
	}

	for (int i = 0; i < stash_count; i++)
		cout << i << ". " << *(double *) fetch(&doubleStash, i) << endl;

	cleanup(&doubleStash);
}
