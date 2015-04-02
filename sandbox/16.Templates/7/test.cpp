#include <string>

#include "MyAutoCounter.h"

using namespace std;

class X {
  static MyAutoCounter<X*> ac;
  static string name;
public:
  X() {
    ac.add(this);
  }
  ~X() {
    ac.remove(this);
  }
};

string X::name {"X"};

MyAutoCounter<X*> X::ac {name};

int main()
{
  X x1;
  X x2;
  X x3;
}
