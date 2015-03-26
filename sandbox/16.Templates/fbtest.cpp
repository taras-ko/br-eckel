#include "fibonacci.h"
#include <iostream>

int main()
{
  using std::cout;

  cout << fibonacci<float>(10) << "\n";
  cout << fibonacci<double>(10) << "\n";
  cout << fibonacci<int>(10) << "\n";

}
