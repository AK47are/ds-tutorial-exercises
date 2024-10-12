#ifndef DOCS_LIB_INCLUDE_ABCLINKLIST_H_
#define DOCS_LIB_INCLUDE_ABCLINKLIST_H_

#include <iostream>

// NOTE: NodeType 必须继承自 AbcNode 类型。
template <typename T, template <typename D> class NodeType>
class AbcLinkList {
  using Abc = AbcLinkList;
  using Node = NodeType<T>;

 protected:
  Node head_;

 public:
  AbcLinkList() = default;
  AbcLinkList(std::initializer_list<T> list) {
    Node* rear = &head_;
    for (auto cur = list.begin(); cur != list.end(); ++cur) {
      rear->CreateNode(*cur);
      rear = rear->next;
    }
  }

  AbcLinkList(Abc& l) {
    Node* rear = &head_;
    for (auto cur = l.Begin(); cur != l.End(); cur = cur->next) {
      rear->CreateNode(cur->data);
      cur = cur->next;
    }
  }

  // NOTE: Begin 和 End 函数事关各函数的遍历。
  virtual Node* Begin() final { return head_.next; }
  virtual const Node* Begin() const final { return head_.next; }
  virtual Node* End() = 0;
  virtual const Node* End() const = 0;

  virtual bool IsEmpty() const { return (Begin() == End()); }

  virtual unsigned Size() const {
    unsigned size = 0;
    for (const Node* cur = Begin(); cur != End(); cur = cur->next) {
      ++size;
    }
    return size;
  }  // 返回遍历过的结点数量。

  virtual Node* GetHead() { return &head_; }

  virtual Node* PrevNode(const Node* start, const unsigned offset) final {
    if (offset == 0) return nullptr;
    if (offset == 1 || start == End() || start->next == End())
      return const_cast<Node*>(start);
    return PrevNode(start->next, offset - 1);
  }

  virtual Node* PrevNode(const Node* start, const Node* pos) final {
    if (start == pos) return nullptr;
    if (start == End() || start->next == End() || start->next == pos)
      return const_cast<Node*>(start);
    return PrevNode(start->next, pos);
  }

  template <typename PosType>  // NOTE: 只能传整型或 Node* 型
  Abc& Insert(const T data, PosType pos) {
    Node* cur = PrevNode(GetHead(), pos);
    cur->CreateNode(data);
    return *this;
  }

  template <typename PosType>  // NOTE: 只能传整型或 Node* 型
  Abc& Erase(PosType pos) {
    Node* cur = PrevNode(GetHead(), pos);
    Node* temp = cur->SkipNext();
    delete temp;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, AbcLinkList& s) {
    for (Node* cur = s.Begin(); cur != s.End(); cur = cur->next) {
      os << " " << cur->data;
    }
    return os;
  }

  virtual ~AbcLinkList() = default;
};
#endif  // DOCS_LIB_INCLUDE_ABCLINKLIST_H_
