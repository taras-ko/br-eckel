#include <iostream>
#include <string>
#include "../../lib/include/debug.h"
class X {
    static int objcnt;
    std::string name;
public:
    X(const std::string& _name) : name(_name) {
        objcnt++;
        print("X()");
    }
    X(const X& x) : name("copy of " + x.name) {
        objcnt++;
        print("X(X&)");
    }
    ~X() {
        objcnt--;
        print("~X()");
    }
    void print(const std::string& text) const {
        std::cout << name << " " << text << " : " << objcnt << std::endl;
    }
};

int X::objcnt = 0;

X f(const X obj)
{
    d(return obj);
}

int main()
{
    d(X x("x"));
    d(X x2 = f(x));
    d(f(x));
}
