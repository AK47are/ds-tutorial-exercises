// 支持带头结点的线性链表结构。Begin(), End() 以及释放内存都要在派生类完成。
// Insert 和 Erase 函数支持下标和指针传入位置。
// 结点构造情况由结点构造函数决定。会传入三个参数 cur, data, cur->next 。

#ifndef DOCS_LIB_INCLUDE_ABCLINKLIST_H_
#define DOCS_LIB_INCLUDE_ABCLINKLIST_H_

#include <iostream>

#include "LinkNode.h"

template <typename T, template <typename D> class NodeType>
class AbcLinkList {
  using ABC = AbcLinkList<T, NodeType>;
  using Node = NodeType<T>;

 protected:
  Node head_;
  Node* end_;  // NOTE: 派生类中必须初始化指向尾节点 next 指向的位置。

 public:
  AbcLinkList() = delete;
  AbcLinkList(Node* end) : end_(end) {}
  AbcLinkList(std::initializer_list<T> list, Node* end) : end_(end) {
    Node* rear = &head_;
    for (auto cur = list.begin(); cur != list.end(); ++cur) {
      rear->next = new Node(rear, *cur, End());
      rear = rear->next;
    }
    head_.SetPrevNode(rear);
  }

  virtual Node* Begin() final { return head_.next; }
  virtual Node* End() final { return end_; }
  virtual bool IsEmpty() final { return (Begin() == End()); }

  virtual unsigned Size() final {
    unsigned size = 0;
    for (Node* cur = Begin(); cur != End(); cur = cur->next) ++size;
    return size;
  }  // 返回遍历过的结点数量。

  virtual Node* PrevNode(const unsigned index) final {  // index = pos - 1
    if (index == 0 || index == -1) return &head_;
    Node* cur = Begin();
    Node* end = End();
    for (int i = 1; i < index - 1 && cur != end; ++i) cur = cur->next;
    return cur;
  }

  virtual Node* PrevNode(const Node* pos) final {
    if (pos == Begin()) return &head_;
    Node* cur = Begin();
    Node* end = End();
    while (cur->next != pos && cur != end) cur = cur->next;
    return cur;
  }

  template <typename PosType>  // NOTE: 只能传整型或 Node* 型
  ABC& Insert(const T data, PosType pos) {
    Node* cur = PrevNode(pos);
    cur->next = new Node(cur, data, cur->next);
    return *this;
  }

  template <typename PosType>  // NOTE: 只能传整型或 Node* 型
  ABC& Erase(PosType pos) {
    Node* cur = PrevNode(pos);
    Node* temp = cur->SkipNext();
    delete temp;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, AbcLinkList& s) {
    for (Node* cur = s.Begin(); cur != s.End(); cur = cur->next)
      os << " " << cur->data;
    return os;
  }

  virtual void Clear() final {
    Node* cur = Begin();
    Node* end = End();
    Node* temp = nullptr;
    while (cur != end) {
      temp = cur;
      cur = cur->next;
      delete temp;
    }
    head_.next = End();
  }

  virtual ~AbcLinkList() { Clear(); }
};
#endif  // DOCS_LIB_INCLUDE_ABCLINKLIST_H_
