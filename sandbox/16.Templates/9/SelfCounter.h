//: C16:SelfCounter.h
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#ifndef SELFCOUNTER_H
#define SELFCOUNTER_H
#include "ValueStack.h"
#include <iostream>
#include <string>

class SelfCounter {
  static int counter;
  static std::string class_name;
  int id;
public:
  SelfCounter() : id(counter++) {
    std::cout << class_name <<" created: " << id << std::endl;
  }
  SelfCounter(const SelfCounter& rv) : id(rv.id){
    std::cout << class_name << " copied: " << id << std::endl;
  }
  SelfCounter operator=(const SelfCounter& rv) {
    std::cout << class_name << " assigned " << rv.id << " to " 
              << id << std::endl;
    return *this; // (4) SelfCounter copied: 0
  }
  ~SelfCounter() {
    std::cout << class_name << " destroyed: "<< id << std::endl;
  }
  friend std::ostream& operator<<( 
    std::ostream& os, const SelfCounter& sc){
    return os << "SelfCounter id: " << sc.id;
  }
};
#endif // SELFCOUNTER_H ///:~
