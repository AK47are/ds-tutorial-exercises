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
  CLinkList(CLinkList& l) {
    this->GetHead()->next = End();
    this->Initialize(l);
  }
  virtual Node* End() override final { return this->GetHead(); }
  virtual const Node* End() const override final { return this->GetHead(); };

  virtual void Clear() override final {
    Node* head = this->GetHead();
    for (Node* temp = head->SkipNext(); temp != End(); temp = head->SkipNext())
      delete temp;
  }

  virtual ~CLinkList() { Clear(); }
};

#endif
