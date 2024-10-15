#ifndef DOCS_LIB_INCLUDE_LINKSTACK_H_
#define DOCS_LIB_INCLUDE_LINKSTACK_H_

#include "LinkList.hpp"

template <typename T>
class LinkStack : public LinkList<T> {
  using List = LinkList<T>;
  using Node = LinkNode<T>;

 private:
  // NOTE: 使用重载让类外无法使用函数。= delete 并不好用。
  Node* End() override { return List::End(); }
  using List::Erase;
  using List::GetHead;
  using List::Insert;
  using List::PrevNode;

 public:
  using LinkList<T>::LinkList;
  // using List::LinkList; clang++ 报错

  const Node* End() const override { return List::End(); }
  const Node* Begin() const { return List::Begin(); }
  LinkStack& Push(const T data) {
    List::Insert(data, List::Begin());
    return *this;
  }

  LinkStack& Pop() {
    List::Erase(List::Begin());
    return *this;
  }

  const T& GetTop() const { return List::Begin()->data; }

  virtual ~LinkStack() = default;
};
#endif
