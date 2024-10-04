#ifndef DOCS_LIB_INCLUDE_LINKSTACK_H_
#define DOCS_LIB_INCLUDE_LINKSTACK_H_

#include "LinkList.h"

template <typename T>
class LinkStack : private LinkList<T> {
  using List = LinkList<T>;
  using Node = LinkNode<T>;

 public:
  LinkStack() = default;
  LinkStack(std::initializer_list<T> il) : List(il){};
  LinkStack& operator=(LinkStack& s) {
    Clear();
    Node* rear = List::PrevNode(-1);
    for (Node* cur = s.Begin(); cur != s.End(); cur = cur->next) {
      rear->next = new Node(rear, cur->data, List::End());
      rear = rear->next;
    }
    return *this;
  }
  virtual bool IsEmpty() { return List::IsEmpty(); }
  virtual unsigned Size() { return List::Size(); }
  LinkStack& Push(const T data) {
    List::Insert(data, List::Begin());
    return *this;
  }
  LinkStack& Pop() {
    List::Erase(List::Begin());
    return *this;
  }
  T GetTop() { return List::Begin()->data; }
  void Clear() { List::Clear(); }
  friend std::ostream& operator<<(std::ostream& os, LinkStack& s) {
    return os << static_cast<List&>(s);
  }
  ~LinkStack() = default;
};
#endif
