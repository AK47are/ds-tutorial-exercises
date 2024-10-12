#ifndef DOCS_LIB_INCLUDE_LINKNODE_H_
#define DOCS_LIB_INCLUDE_LINKNODE_H_

template <typename T, template <typename> class NodeType>
struct AbcNode {
  T data;
  NodeType<T>* next;

  virtual NodeType<T>* SkipNext() final {  // 跳过下一个节点。
    if (next == nullptr) return nullptr;
    NodeType<T>* temp = next;
    next = temp->next;
    return temp;
  }

  virtual NodeType<T>& CreateNode(const T& data) = 0;
  virtual ~AbcNode() = default;
};

template <typename T>
struct LinkNode : AbcNode<T, LinkNode> {
  virtual LinkNode& CreateNode(const T& data) override {
    this->next = new LinkNode{data, this->next};
    return *this;
  }
};

template <typename T>
struct DLinkNode : AbcNode<T, DLinkNode> {
  DLinkNode<T>* prev;
  virtual DLinkNode& CreateNode(const T& data) override {
    this->next = new DLinkNode{this, data, this->next};
    return *this;
  }
};

#endif
