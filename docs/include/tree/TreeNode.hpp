#ifndef TREENODE_HPP_
#define TREENODE_HPP_

template <typename T, template <typename> class NodeType>
struct TBtNode {
  using Node = NodeType<T>;

  T data;
  Node* left = nullptr;
  Node* right = nullptr;

  TBtNode() = default;
  TBtNode(const T& d) : data(d) {}
};

template <typename T>
struct BtNode : public TBtNode<T, BtNode> {
  using TBtNode<T, BtNode>::TBtNode;
};
#endif
