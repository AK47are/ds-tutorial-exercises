#ifndef DOCS_LIB_INCLUDE_ABCLINKLIST_H_
#define DOCS_LIB_INCLUDE_ABCLINKLIST_H_

#include <iostream>

// NOTE: NodeType 必须继承自 AbcNode 或其子类类型。
template <typename T, template <typename D> class NodeType>
class AbcLinkList {
  using Abc = AbcLinkList;
  using Node = NodeType<T>;

 private:
  Node head_;

 protected:
  void Initialize(std::initializer_list<T> list) {
    Node* rear = GetHead();
    for (auto cur = list.begin(); cur != list.end(); ++cur) {
      rear = rear->CreateNext(*cur);
    }
  }

  void Initialize(const Abc& l) {
    Node* rear = &head_;
    for (auto cur = l.Begin(); cur != l.End(); cur = cur->next) {
      rear = rear->CreateNext(cur->data);
    }
  }

 public:
  AbcLinkList() = default;
  AbcLinkList(AbcLinkList&&) = delete;
  AbcLinkList& operator=(AbcLinkList&&) = delete;

  AbcLinkList& operator=(const AbcLinkList& l) {
    if (this != &l) Clear(), Initialize(l);
    return *this;
  }

  // NOTE: Begin 和 End 函数事关各函数的遍历。
  Node* Begin() { return head_.next; }
  const Node* Begin() const { return head_.next; }
  virtual Node* End() = 0;
  virtual const Node* End() const = 0;

  bool IsEmpty() const { return (Begin() == End()); }

  unsigned Size() const {
    unsigned size = 0;
    for (const Node* cur = Begin(); cur != End(); cur = cur->next) {
      ++size;
    }
    return size;
  }  // 返回遍历过的结点数量。

  Node* GetHead() { return &head_; }
  const Node* GetHead() const { return &head_; }

  Node* PrevNode(Node* start, const unsigned offset) {
    if (start == Begin() && offset == 0) return GetHead();
    if (offset == 0) return nullptr;
    if (offset == 1 || start == End() || start->next == End()) return start;
    return PrevNode(start->next, offset - 1);
  }

  Node* PrevNode(Node* start, const Node* pos) {
    if (start == Begin() && start == pos) return GetHead();
    if (start == pos) return nullptr;
    if (start == End() || start->next == End() || start->next == pos)
      return start;
    return PrevNode(start->next, pos);
  }

  template <typename PosType>  // NOTE: 只能传整型或 Node* 型
  Abc& Insert(const T data, PosType pos) {
    Node* cur = PrevNode(Begin(), pos);
    cur->CreateNext(data);
    return *this;
  }

  template <typename PosType>  // NOTE: 只能传整型或 Node* 型
  Abc& Erase(PosType pos) {
    Node* cur = PrevNode(Begin(), pos);
    Node* temp = cur->SkipNext();
    delete temp;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const AbcLinkList& s) {
    for (const Node* cur = s.Begin(); cur != s.End(); cur = cur->next) {
      os << cur->data;
    }
    return os;
  }

  void Clear() {
    Node* head = this->GetHead();
    for (Node* temp = head->SkipNext(); temp != End(); temp = head->SkipNext())
      delete temp;
  }

  virtual ~AbcLinkList() = default;
};

#endif  // DOCS_LIB_INCLUDE_ABCLINKLIST_H_
