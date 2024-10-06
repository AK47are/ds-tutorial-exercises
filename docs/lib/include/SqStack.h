#ifndef DOCS_LIB_INCLUDE_SQSTACK_H_
#define DOCS_LIB_INCLUDE_SQSTACK_H_

#include <initializer_list>

#include "SqList.h"
template <typename T, size_t MAX>
class SqStack : public SqList<T, MAX> {
  using List = SqList<T, MAX>;

 private:
  SqStack& Insert(const T data, const size_t index) = delete;

  T& operator[](const size_t index) override { return List::operator[](index); }

  SqStack& Erase(const size_t index) = delete;

 public:
  SqStack() = default;
  SqStack(std::initializer_list<T> il) : List(il){};

  SqStack& Push(T data) {
    operator[](List::length_) = data;
    ++List::length_;
    return *this;
  }

  SqStack& Pop() {
    --List::length_;
    return *this;
  }

  T GetTop() { return operator[](List::Size() - 1); }

  friend std::ostream& operator<<(std::ostream& os, SqStack& s) {
    for (size_t i = 0; i < s.Size(); ++i) os << " " << s[s.Size() - 1 - i];
    return os;
  }
  ~SqStack() = default;
};
#endif
