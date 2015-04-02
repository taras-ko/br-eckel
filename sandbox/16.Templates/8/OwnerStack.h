#ifndef OWNERSTACK_H
#define OWNERSTACK_H

#include <vector>

template<typename T> class Stack {
  std::vector<T*> stack;
  bool own;
public:
  Stack(bool own = true) : own(own) {}
  ~Stack();
  void push(T* ptr) {
    stack.push_back(ptr);
  }
  T* peek() const {
    return stack.back();
  }
  T* pop() {
    T* ret = stack.back();
    stack.pop_back();
    return ret;
  }
  bool owns() const { return own; }
  void owns(bool newownership) {
    own = newownership;
  }
  // Auto-type conversion: true if not empty:
  operator bool() const { return !stack.empty(); }
};

template<class T> Stack<T>::~Stack() {
  if (!own)
    return;

  while (!stack.empty()) {
    delete stack.back();
    stack.pop_back();
  }
}
#endif // OWNERSTACK_H ///:~
