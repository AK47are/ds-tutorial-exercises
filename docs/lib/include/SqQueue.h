// TODO: 待全面测试。
#ifndef DOCS_LIB_INCLUDE_SQEUEUE_H_
#define DOCS_LIB_INCLUDE_SQEUEUE_H_

#include <iostream>

#include "SqList.h"
template <typename T, size_t MAX>
class SqQueue : public SqList<T, MAX> {
  using List = SqList<T, MAX>;

 private:
  size_t front;
  size_t rear;

  SqQueue& Insert(const T data, const size_t index) = delete;

  T& operator[](const size_t index) override { return List::operator[](index); }

  SqQueue& Erase(const size_t index) = delete;
  void Clear(const size_t pos = 0) = delete;

 public:
  SqQueue() : List(), front(0), rear(-1){};
  SqQueue(std::initializer_list<T> il)
      : List(il), front(0), rear(il.Size() - 1){};
  T GetFront() { return operator[](front); }
  T GetRear() { return operator[](rear); }
  SqQueue& EnQueue(const T data) {
    if (!List::IsFull()) {
      rear = (rear + 1) % MAX;
      operator[](rear) = data;
      ++List::length_;
    }
    return *this;
  }
  SqQueue& DeQueue() {
    if (!List::IsEmpty()) {
      front = (front + 1) % MAX;
      --List::length_;
    }
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, SqQueue& s) {
    std::cout << s[s.front - 1] << "\n";
    for (size_t i = 0; i < s.Size(); ++i) {
      os << " " << s[(s.front + i) % MAX];
    }
    return os;
  }
  ~SqQueue() = default;
};
#endif
