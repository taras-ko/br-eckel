//: C15:AddingVirtuals.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Adding virtuals in derivation
#include <iostream>
#include <string>
using namespace std;

class Pet {
  string pname;
public:
  Pet(const string& petName) : pname(petName) {}
  virtual string name() const = 0; //{ return pname; }
  virtual string speak() const = 0;//{ return ""; }
};

//string Pet::name() const { return pname; };
string Pet::speak() const { return ""; };

class Dog : public Pet {
  string name;
public:
  Dog(const string& petName) : Pet(petName) {}
  // New virtual function in the Dog class:
  virtual string sit() const {
    return Pet::name() + " sits";
  }
  string speak() const { // Override
    return Pet::name() + " says 'Bark!'";
  }
  string name() const { return Pet::name() + " " + name; }
};

int main() {
	Dog d("bob");
//  Pet* p[] = {new Dog("bob")};
 // cout << "p[0]->speak() = "
  //     << p[0]->speak() << endl;
//! cout << "p[1]->sit() = "
//!      << p[1]->sit() << endl; // Illegal
} ///:~
