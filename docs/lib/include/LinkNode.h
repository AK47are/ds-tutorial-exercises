#ifndef DOCS_LIB_INCLUDE_LINKNODE_H_
#define DOCS_LIB_INCLUDE_LINKNODE_H_
template <typename T>
struct LinkNode {
  T data;
  LinkNode<T>* next = nullptr;

  LinkNode() = default;
  LinkNode(LinkNode<T>* p, const T d, LinkNode<T>* n) : data(d), next(n) {}
  LinkNode* SkipNext() {  // 跳过下一个节点。
    if (next == nullptr) return nullptr;
    LinkNode* temp = next;
    next = temp->next;
    return temp;
  }
  void SetPrevNode(LinkNode* rear) {}
};

template <typename T>
struct DLinkNode {  // HACK: 需要优化不同类型结点联系。
  DLinkNode<T>* prev = nullptr;
  T data;
  DLinkNode<T>* next = nullptr;

  DLinkNode() = default;
  DLinkNode(DLinkNode<T>* p, const T d, DLinkNode<T>* n)
      : prev(p), data(d), next(n) {}
  void SetPrevNode(DLinkNode* rear) { prev = rear; }
  DLinkNode* SkipNext() {  // 跳过下一个节点。
    if (next == nullptr) return nullptr;
    DLinkNode* temp = next;
    next = temp->next;
    next->prev = this;
    return temp;
  }
};

#endif
