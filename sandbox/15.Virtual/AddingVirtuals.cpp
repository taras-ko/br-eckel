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
  virtual string get_name() const = 0; //{ return pname; }
  virtual string speak() const = 0;//{ return ""; }
};

string Pet::get_name() const { return pname; }
string Pet::speak() const { return ""; }

class Dog : public Pet {
  string name;
public:
  Dog(const string& _name) : Pet("Dog"), name(_name) {}
  // New virtual function in the Dog class:
  virtual string sit() const {
    return get_name() + " sits";
  }
  virtual string speak() const { // Override
    return get_name() + " says 'Bark!'";
  }
  virtual string get_name() const { return Pet::get_name() + " " + name; }
};

int main() {
  Pet* p[] = { new Dog("Simba") };
  cout << "p[0]->speak() = "
       << p[0]->speak() << endl;
//  cout << "p[0]->sit() = "
 //      << p[0]->sit() << endl; // Illegal
} ///:~
