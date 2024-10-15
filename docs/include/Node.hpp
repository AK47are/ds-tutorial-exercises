#ifndef DOCS_LIB_INCLUDE_LINKNODE_H_
#define DOCS_LIB_INCLUDE_LINKNODE_H_

template <typename T, template <typename> class NodeType>
struct AbcNode {
  T data;
  NodeType<T>* next;

  AbcNode() = default;
  AbcNode(const T& d, NodeType<T>* n) : data(d), next(n) {}
  NodeType<T>* SkipNext() {  // 跳过下一个节点。
    if (next == nullptr) return nullptr;
    NodeType<T>* temp = next;
    next = temp->next;
    return temp;
  }

  virtual NodeType<T>* CreateNext(const T& d) = 0;
  virtual ~AbcNode() = default;
};

template <typename T>
struct LinkNode : AbcNode<T, LinkNode> {
  LinkNode() = default;
  LinkNode(const T& d, LinkNode* n) : AbcNode<T, LinkNode>(d, n) {}
  virtual LinkNode* CreateNext(const T& d) override final {
    return this->next = new LinkNode{d, this->next};
  }
  virtual ~LinkNode() = default;
};

template <typename T>
struct DLinkNode : AbcNode<T, DLinkNode> {
  DLinkNode<T>* prev;

  DLinkNode() = default;
  DLinkNode(DLinkNode* p, const T& d, DLinkNode* n)
      : AbcNode<T, DLinkNode>(d, n), prev(p) {}
  virtual DLinkNode* CreateNext(const T& d) override final {
    return this->next = new DLinkNode{this, d, this->next};
  }
  virtual ~DLinkNode() = default;
};

#endif
