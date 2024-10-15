#ifndef DOCS_LIB_INCLUDE_LINKLIST_H_
#define DOCS_LIB_INCLUDE_LINKLIST_H_

#include "AbcLinkList.hpp"
#include "Node.hpp"

template <typename T, template <typename> class NodeType = LinkNode>
class LinkList : public AbcLinkList<T, NodeType> {
  using Abc = AbcLinkList<T, NodeType>;
  using Node = NodeType<T>;

 public:
  LinkList() { this->GetHead()->next = End(); }
  LinkList(std::initializer_list<T> li) {
    this->GetHead()->next = End();
    this->Initialize(li);
  }
  LinkList(const LinkList& l) {
    this->GetHead()->next = End();
    this->Initialize(l);
  }
  Node* End() override { return nullptr; }
  const Node* End() const override { return nullptr; };

  virtual ~LinkList() { this->Clear(); }
};

#endif
