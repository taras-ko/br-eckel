/* Using the Standard C++ Library vector as an underlying
implementation, create a Set template class that accepts
only one of each type of object that you put into it. Make
a nested iterator class that supports the “end sentinel”
concept in this chapter. Write test code for your Set in
main( ), and then substitute the Standard C++ Library set
template to verify that the behavior is correct. */

#include <vector>
#include "require.h"
template<typename T>
class Set {
  std::vector<T> set;
public:
  Set() {};
  ~Set();
  void insert(T elem);
  class iterator;
  friend iterator;
  class iterator {
    Set& _Set;
    int index;
  public:
    iterator(Set& __Set)
      : _Set(__Set), index(0) {}
    // End sentinel
    iterator(Set& __Set, bool)
      : _Set(__Set), index(_Set.set.size()) {}

    iterator& operator++() {
      require(++index <= _Set.set.size(),
        "PStash::iterator::operator++ "
        "moves index out of bounds");
      return *this;
    }
    T operator*() const { return _Set.set[index]; }
    bool operator!=(const iterator& rv) const {
      return index != rv.index;
    }
  };
  iterator begin() { return iterator(*this); }
  iterator end() { return iterator(*this, true); }
};

// Destruction of contained objects:
template<typename T>
Set<T>::~Set() {
  /*
  while (!set.empty()) {
    T elem = set.back();
    std::cout << "Deleteing " << *elem << std::endl;
    set.pop_back();
    delete elem;
  }
  */
}

template<typename T>
void Set<T>::insert(T elem) {
  for (int i = 0; i < set.size(); i++)
    if (set[i] == elem)
        return;
  set.push_back(elem);
}

