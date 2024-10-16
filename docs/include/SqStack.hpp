#ifndef DOCS_LIB_INCLUDE_SQSTACK_H_
#define DOCS_LIB_INCLUDE_SQSTACK_H_

#include "SqList.hpp"
template <typename T, size_t MAX>
class SqStack : public SqList<T, MAX> {
  using List = SqList<T, MAX>;

 private:
  using List::Erase;
  using List::Insert;
  using List::operator[];

 public:
  using List::SqList;
  SqStack& Push(T data) {
    Insert(data, this->Size());
    return *this;
  }
  SqStack& Pop() {
    Erase(this->Size() - 1);
    return *this;
  }
  const T& GetTop() const { return this->operator[](List::Size() - 1); }
  ~SqStack() = default;
};
#endif
