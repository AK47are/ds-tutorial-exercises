#ifndef DOCS_LIB_INCLUDE_LINKQUEUE_H_
#define DOCS_LIB_INCLUDE_LINKQUEUE_H_

#include "LinkList.h"

template <typename T>
class LinkQueue : private LinkList<T> {
  using List = LinkList<T>;
  using Node = LinkNode<T>;

 private:
  Node* rear;

 public:
  LinkQueue() : List(), rear(List::PrevNode(-1)){};

  LinkQueue(std::initializer_list<T> il)
      : List(il), rear(List::PrevNode(List::End())){};
  virtual bool IsEmpty() { return List::IsEmpty(); }
  virtual unsigned Size() { return List::Size(); }
  LinkQueue& EnQueue(const T data) {
    rear->next = new Node(rear, data, nullptr);
    rear = rear->next;
    return *this;
  }
  LinkQueue& DeQueue() { return static_cast<LinkQueue&>(List::Erase(-1)); }
  T GetFront() { return List::Begin()->data; }
  T GetRear() { return rear->data; }
  void Clear() { List::Clear(); }
  friend std::ostream& operator<<(std::ostream& os, LinkQueue& s) {
    return os << static_cast<List&>(s);
  }
  ~LinkQueue() = default;
};
#endif
