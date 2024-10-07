#ifndef DOCS_LIB_INCLUDE_SQLIST_H_
#define DOCS_LIB_INCLUDE_SQLIST_H_
#include <initializer_list>
#include <iostream>
template <typename T, size_t MAX>
class SqList {
 protected:
  T* arr_;
  size_t length_;

 public:
  SqList() : length_(0) { arr_ = new T[MAX]; }
  SqList(std::initializer_list<T> il) {
    arr_ = new T[MAX];
    int pos = 0;
    for (auto cur = il.begin(); cur != il.end(); ++cur) arr_[pos++] = *cur;
    length_ = pos;
  }

  virtual bool IsEmpty() const final { return (length_ == 0); }
  virtual bool IsFull() const final { return (length_ == MAX); }
  virtual size_t Size() const final { return length_; }
  virtual T& operator[](const size_t index) { return arr_[index]; }

  SqList& Insert(const T x, const size_t index) {
    if (index > length_) return *this;
    for (int i = length_; i > index; --i) arr_[i] = arr_[i - 1];
    arr_[index] = x;
    ++length_;
    return *this;
  }

  SqList& Erase(const size_t index) {
    for (int i = index; i < length_ - 1; ++i) arr_[i] = arr_[i + 1];
    --length_;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, SqList& s) {
    for (size_t i = 0; i < s.length_; ++i) os << " " << s.arr_[i];
    return os;
  }

  void Clear(const size_t pos = 0) { length_ = pos; }

  ~SqList() { delete[] arr_; }
};
#endif
