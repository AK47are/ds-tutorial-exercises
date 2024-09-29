#ifndef DOCS_LIB_INCLUDE_CDLINKLIST_H_
#define DOCS_LIB_INCLUDE_CDLINKLIST_H_
#include <initializer_list>
#include <iostream>

#include "AbcLinkList.h"
template <typename T>
class CdLinkList : public AbcLinkList<T, DLinkNode> {
  using ABC = AbcLinkList<T, DLinkNode>;
  using Node = DLinkNode<T>;

 public:
  CdLinkList() = default;
  CdLinkList(std::initializer_list<T> list) : ABC(list) {}
  virtual Node* End() override { return ABC::PreNode(-1); }
  virtual ~CdLinkList() = default;
};
#endif
