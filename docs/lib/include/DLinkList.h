#ifndef DOCS_LIB_INCLUDE_DLINKLIST_H_
#define DOCS_LIB_INCLUDE_DLINKLIST_H_
#include <initializer_list>
#include <iostream>

#include "AbcLinkList.h"

template <typename T>
class DLinkList : public AbcLinkList<T, DLinkNode> {
  using ABC = AbcLinkList<T, DLinkNode>;
  using Node = DLinkNode<T>;

 public:
  DLinkList() : ABC(nullptr){};
  DLinkList(std::initializer_list<T> list) : ABC(list, nullptr) {}
  virtual ~DLinkList() {}
};
#endif
