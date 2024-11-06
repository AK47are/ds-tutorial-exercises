#ifndef SQQUEUE_HPP_
#define SQQUEUE_HPP_

#include "SqList.hpp"
template <typename T, size_t MAX>
class SqQueue : public SqList<T, MAX> {
  using List = SqList<T, MAX>;

 private:
  size_t front;
  size_t rear;

  SqQueue& operator=(const SqQueue&) = delete;
  using List::operator[];
  using List::Clear;
  using List::Erase;
  using List::Insert;

 public:
  SqQueue() : List(), front(0), rear(-1) {}
  SqQueue(std::initializer_list<T> il)
      : List(il), front(0), rear(il.size() - 1) {}

  const T& GetFront() const { return this->operator[](front); }
  const T& GetRear() const { return this->operator[](rear); }
  void EnQueue(const T data) {
    if (!List::IsFull()) {
      rear = (rear + 1) % MAX;
      List::operator[](rear) = data;
      ++this->GetLength();
    }
  }
  void DeQueue() {
    T rtn;
    if (!List::IsEmpty()) {
      rtn = operator[](front);
      front = (front + 1) % MAX;
      --this->GetLength();
    }
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
