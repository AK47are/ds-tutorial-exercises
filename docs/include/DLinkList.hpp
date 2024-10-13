#ifndef DOCS_LIB_INCLUDE_DLINKLIST_H_
#define DOCS_LIB_INCLUDE_DLINKLIST_H_

#include "LinkList.hpp"

template <typename T>
using DLinkList = LinkList<T, DLinkNode>;

#endif
