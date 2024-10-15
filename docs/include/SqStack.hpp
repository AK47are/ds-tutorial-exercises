#ifndef DOCS_LIB_INCLUDE_SQSTACK_H_
#define DOCS_LIB_INCLUDE_SQSTACK_H_

#include "SqList.hpp"
template <typename T, size_t MAX>
class SqStack : public SqList<T, MAX> {
  using List = SqList<T, MAX>;

 private:
  SqStack& Insert(const T data, const size_t index) {
    List::Insert(data, index);
    return *this;
  }

  SqStack& Erase(const size_t index) {
    List::Erase(index);
    return *this;
  }

  const T& operator[](const size_t index) const {
    return List::operator[](index);
  }

 public:
  using List::SqList;
  SqStack& Push(T data) { return Insert(data, this->Size()); }
  SqStack& Pop() { return Erase(this->Size() - 1); }
  const T& GetTop() const { return this->operator[](List::Size() - 1); }

  friend std::ostream& operator<<(std::ostream& os, const SqStack& s) {
    for (size_t i = 0; i < s.Size(); ++i) {
      os << s[s.Size() - 1 - i];
    }
    return os;
  }

  ~SqStack() = default;
};
#endif
