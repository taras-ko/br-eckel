/* Make a Stash that holds doubles. Fill it with 25 double
 * values, then print them out to the console. */

#include  <stdlib.h>
#include <iostream>

#include <Stash.h>

using namespace std;
int main()
{
	Stash s;

	const unsigned short stash_count = 25;

	s.initialize(stash_count * sizeof(double));

	for (int i = 0; i < stash_count; i++) {
		double number = drand48();
		s.add(&number);
	}

	for (int i = 0; i < stash_count; i++)
		cout << i << ". " << *(double *) s.fetch(i) << endl;

	s.cleanup();
}
