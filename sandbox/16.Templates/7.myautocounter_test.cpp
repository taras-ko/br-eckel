#include <string>

#include "MyAutoCounter.h"

using namespace std;

class X {
  static MyAutoCounter<X*> ac;
  string name;
public:
  X() {
    //name = "X(" + std::to_string(ac.get_count()) + ")";
    //cout << name << endl;
    ac.add(this);
  }
  ~X() {
    ac.remove(this);
  }
};

MyAutoCounter<X*> X::ac;

int main()
{
  X x1;
  X x2;
  X x3;
}
