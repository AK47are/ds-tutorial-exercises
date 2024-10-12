#ifndef DOCS_LIB_INCLUDE_CLINKLIST_H_
#define DOCS_LIB_INCLUDE_CLINKLIST_H_
#include <initializer_list>
#include <iostream>

#include "AbcLinkList.h"
template <typename T>
class CLinkList : public AbcLinkList<T, LinkNode> {
  using ABC = AbcLinkList<T, LinkNode>;
  using Node = LinkNode<T>;

 public:
  CLinkList() : ABC(ABC::PrevNode(-1)){};
  CLinkList(std::initializer_list<T> list) : ABC(list, ABC::PrevNode(-1)) {}
  virtual ~CLinkList() = default;
};
#endif
