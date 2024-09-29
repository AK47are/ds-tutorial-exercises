#ifndef DOCS_LIB_INCLUDE_LINKLIST_H_
#define DOCS_LIB_INCLUDE_LINKLIST_H_
#include <initializer_list>
#include <iostream>

#include "AbcLinkList.h"

template <typename T>  // 有头结点的单链表。
class LinkList : public AbcLinkList<T, LinkNode> {
  using ABC = AbcLinkList<T, LinkNode>;
  using Node = LinkNode<T>;

 public:
  LinkList() : ABC(nullptr) {}
  LinkList(std::initializer_list<T> list) : ABC(list, nullptr) {}
  virtual ~LinkList() {}
};

#endif
