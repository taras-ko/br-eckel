#include <iostream>
#include <set>

#include "Set.h"

using std::cout;
using std::endl;

int main()
{
#if 0
  Set<int> set;
#else
  std::set<int> set;
#endif

  for (int i = 0; i < 10; i++)
    set.insert(i);
  for (int i = 0; i < 10; i++)
    set.insert(i);

#if 0
  Set<int>::iterator it = set.begin();
#else
  std::set<int>::iterator it = set.begin();
#endif

  for (; it != set.end(); ++it) {
    cout << *it << ' ';
  }
  cout << endl;
/*
  for (pos = s.begin(); pos < s.end(); ++pos) {
    cout << *pos << ' ';
  }
  cout << endl;
*/
}
