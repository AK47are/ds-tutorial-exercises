#ifndef DOCS_LIB_INCLUDE_SQEUEUE_H_
#define DOCS_LIB_INCLUDE_SQEUEUE_H_

#include "SqList.hpp"
template <typename T, size_t MAX>
class SqQueue : public SqList<T, MAX> {
  using List = SqList<T, MAX>;

 private:
  size_t front;
  size_t rear;

  const T& operator[](const size_t index) const {
    return List::operator[](index);
  }
  SqQueue& Insert(const T data, const size_t index) = delete;
  SqQueue& Erase(const size_t index) = delete;
  void Clear(const size_t pos = 0) = delete;

 public:
  SqQueue() : List(), front(0), rear(-1){};
  SqQueue(std::initializer_list<T> il)
      : List(il), front(0), rear(il.Size() - 1){};

  const T& GetFront() const { return List::operator[](front); }
  const T& GetRear() const { return List::operator[](rear); }
  SqQueue& EnQueue(const T data) {
    if (!List::IsFull()) {
      rear = (rear + 1) % MAX;
      List::operator[](rear) = data;
      ++this->length_;
    }
    return *this;
  }
  SqQueue& DeQueue() {
    if (!List::IsEmpty()) {
      front = (front + 1) % MAX;
      --this->length_;
    }
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const SqQueue& s) {
    std::cout << s[s.front - 1] << "\n";
    for (size_t i = 0; i < s.Size(); ++i) {
      os << s[(s.front + i) % MAX];
    }
    return os;
  }
  ~SqQueue() = default;
};
#endif
