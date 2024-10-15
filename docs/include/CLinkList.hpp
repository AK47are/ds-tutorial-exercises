#ifndef DOCS_LIB_INCLUDE_CLINKLIST_H_
#define DOCS_LIB_INCLUDE_CLINKLIST_H_

#include "AbcLinkList.hpp"
#include "Node.hpp"

template <typename T, template <typename> class NodeType = LinkNode>
class CLinkList : public AbcLinkList<T, NodeType> {
  using Abc = AbcLinkList<T, NodeType>;
  using Node = NodeType<T>;

 public:
  CLinkList() { this->GetHead()->next = End(); }
  CLinkList(std::initializer_list<T> li) {
    this->GetHead()->next = End();
    this->Initialize(li);
  }
  CLinkList(const CLinkList& l) {
    this->GetHead()->next = End();
    this->Initialize(l);
  }

  Node* End() override { return this->GetHead(); }
  const Node* End() const override { return this->GetHead(); };

  virtual ~CLinkList() { this->Clear(); }
};

#endif
