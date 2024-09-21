#ifndef SQLIST_H
#define SQLIST_H
#include <initializer_list>
#include <iostream>
#include <ostream>
template <typename T, size_t MAX>
class sqlist {
 private:
  T arr[MAX];
  size_t length;

 public:
  sqlist() : length(0) {}

  sqlist(std::initializer_list<T> il) {
    int pos = 0;
    for (auto p = il.begin(); p != il.end() && pos != MAX; ++pos, ++p)
      arr[pos] = *p;
    length = pos;
  }

  sqlist(const sqlist& s) : length(s.length) {
    for (int i = 0; i < length && i < MAX; ++i) arr[i] = s.arr[i];
  }

  bool empty() const { return (length == 0); }

  bool full() const { return (length == MAX); }

  size_t size() const { return length; }

  T& operator[](const size_t pos) { return arr[pos]; }

  bool insert(T x, const size_t pos) {
    if (pos > length) return false;
    for (int i = length; i > pos; --i) arr[i] = arr[i - 1];
    arr[pos] = x;
    ++length;
    return true;
  }

  bool erase(const size_t pos) {
    if (pos > length) return false;
    for (int i = pos; i < length - 1; ++i) arr[i] = arr[i + 1];
    --length;
    return true;
  }

  size_t index_find(const T i) {
    for (size_t j = 0; j < length; ++j)
      if (arr[j] == i) return j;
    std::cerr << "No find!" << "\n";
    return length;
  }
  friend std::ostream& operator<<(std::ostream& os, sqlist& s) {};  // TODO:

  T& front() { return arr[0]; }
  T& back() { return arr[length - 1]; }
  T* begin() { return &arr[0]; }
  T* end() { return &arr[length]; }
  ~sqlist() {}
};
#endif
