#ifndef LINKSTACK_HPP_
#define LINKSTACK_HPP_

#include "LinkList.hpp"

template <typename T>
class LinkStack : public LinkList<T> {
  using List = LinkList<T>;
  using Node = LinkNode<T>;

 private:
  // NOTE: 使用重载让类外无法使用函数。= delete 并不好用。
  using List::Erase;
  using List::GetHead;
  using List::Insert;
  using List::PrevNode;

 public:
  using LinkList<T>::LinkList;
  // using List::LinkList; clang++ 报错
  // 非const 对应方法被隐藏。
  const Node* End() const override { return List::End(); }
  const Node* Begin() const { return List::Begin(); }
  void Push(const T data) { List::Insert(data, List::Begin()); }
  void Pop() { List::Erase(List::Begin()); }
  const T& GetTop() const { return List::Begin()->data; }
  virtual ~LinkStack() = default;
};
#endif
