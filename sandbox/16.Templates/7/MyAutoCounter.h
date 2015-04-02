#ifndef MyAutoCounter_H
#define MyAutoCounter_H
#include "require.h"
#include <iostream>
#include <set> // Standard C++ Library container
#include <string>

template <typename T>
class MyAutoCounter {
  static int count;
  std::string name;
  std::set<T> trace;
  // Prevent assignment and copy-construction:
  MyAutoCounter(const MyAutoCounter&);
  void operator=(const MyAutoCounter&);
public:
  MyAutoCounter(std::string& _name = "") : name(_name) {}
  ~MyAutoCounter() {
      std::cout << "~CleanupCheck()"<< std::endl;
      require(trace.size() == 0,
       "Not all objects are cleaned up");
    }
  void add(T obj) {
    std::cout << "creating " << ++count << " "
      << name << std::endl;
    trace.insert(obj);
  }
  void remove (T obj) {
     require(trace.erase(obj) == 1,
        "Attempt to delete Obj twice");
     std::cout << "destroying " << count--
              << " " << name << std::endl;
  }
  int get_count() { return count; }

  // Print both objects and pointers:
  friend std::ostream& operator<<(
    std::ostream& os, const MyAutoCounter& ac){
    return os << "MyAutoCounter " << ac.count;
  }
  friend std::ostream& operator<<(
    std::ostream& os, const MyAutoCounter* ac){
    return os << "MyAutoCounter " << ac->count;
  }
};

template <typename T>
int MyAutoCounter<T>::count = 0;


#endif // MyAutoCounter_H ///:~
