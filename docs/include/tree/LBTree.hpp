#ifndef LKBTREE_HPP_
#define LKBTREE_HPP_

#include <initializer_list>
#include <iostream>

#include "../link/LinkQueue.hpp"
#include "TreeNode.hpp"

// NOTE:NodeType 必须继承自 BtNode 。
template <typename T, template <typename> class NodeType = BtNode>
class LBTree {
  using Node = NodeType<T>;
  using init = std::initializer_list<T>;

  Node* root_;

 protected:
  Node* PreCreate(const T prev_order[], const T in_order[], const int& size) {
    if (size <= 0) return nullptr;
    Node* root = new Node(prev_order[0]);
    int root_index = 0;
    while (in_order[root_index] != prev_order[0]) ++root_index;
    root->left = PreCreate(prev_order + 1, in_order, root_index);
    root->right = PreCreate(prev_order + root_index + 1,
                            in_order + root_index + 1, size - root_index - 1);
    return root;
  }

  Node* PostCreate(const T post_order[], const T in_order[], const int& size) {
    if (size <= 0) return nullptr;
    Node* root = new Node(post_order[size - 1]);
    int root_index = 0;
    while (in_order[root_index] != post_order[size - 1]) ++root_index;
    root->left = PostCreate(post_order, in_order, root_index);
    root->right = PostCreate(post_order + root_index, in_order + root_index + 1,
                             size - root_index - 1);
    return root;
  }

  int Depth(const Node* root, const Node* target, int depth) const {
    if (!root) return -1;
    if (root->left == target || root->right == target) return depth + 1;
    int left_depth = Depth(root->left, target, depth + 1),
        right_depth = Depth(root->right, target, depth + 1);
    if (left_depth != -1) return left_depth;
    return right_depth;
  }

 public:
  enum { PreOrder = 1, InOrder, PostOrder };
  LBTree() : root_(nullptr) {}
  LBTree(const LBTree& t) { Copy(t.GetRoot(), GetRoot()); }

  // 存储结点指针的数组。支持不添加左结点。
  LBTree(Node* arr[], int length) {
    if (length == 0) return;
    root_ = new Node(arr[0]);
    Node* temp = GetRoot();
    for (int i = 1; i < length; ++i) {
      temp = arr[i];
      if (i * 2 + 1 < length) {
        if (temp) temp->left = arr[i * 2 + 1];
        if (temp) temp->right = arr[i * 2 + 2];
      }
    }
  }

  // 根据前序或后序和中序序列构造。
  LBTree(const T order[], const T in_order[], const int& size, int flag) {
    if (flag == PreOrder)
      GetRoot() = PreCreate(order, in_order, size);
    else if (flag == PostOrder)
      GetRoot() = PostCreate(order, in_order, size);
  }

  // 按完全二叉树构造。
  LBTree(const init& li) {
    if (li.size() == 0) return;
    root_ = new Node(*li.begin());
    LinkQueue<Node*> queue{GetRoot()};
    Node* temp = GetRoot();
    auto cur = li.begin() + 1;
    while (cur != li.end()) {
      temp->left = new Node(*cur), ++cur;
      queue.EnQueue(temp->left);
      if (cur == li.end()) break;
      temp->right = new Node(*cur), ++cur;
      queue.EnQueue(temp->right);
      temp = queue.GetFront();
      queue.DeQueue();
    }
  }

  void Copy(const Node*& b1_root, const Node*& b2_root) {
    if (!b1_root) return;
    b2_root = new Node(b1_root->data);
    Copy(b1_root->left, b2_root->left);
    Copy(b1_root->rchild, b2_root->rchild);
  }

  LBTree& operator=(const LBTree& t) {
    Delete(GetRoot());
    Copy(t.GetRoot(), GetRoot());
    return *this;
  }

  Node*& GetRoot() { return root_; }
  const Node* GetRoot() const { return root_; }

  int Size(const Node* root) const {
    if (!root) return 0;
    int size = 1;
    size += Size(root->left);
    size += Size(root->right);
    return size;
  }
  int Size() const { return Size(GetRoot()); }

  int Height() const { return Height(GetRoot()); }
  int Height(const Node* root) const {
    // 一定要是 -1 ,不然会统计成经过结点的数量而不是边。
    // 也可以设计成自上向下的形式。
    if (!root) return -1;
    int left_height = Height(root->left), right_height = Height(root->right);
    return 1 + ((left_height < right_height) ? right_height : left_height);
  }

  // 不能简单地通过高度相减得到。
  int Depth(const Node* root) const {
    if (GetRoot() == root)
      return 0;
    else
      return Depth(GetRoot(), root, 0);
  }

  Node* Find(Node* root, const T& data) {
    if (!root) return nullptr;
    if (root->data == data) return root;
    Node* node = nullptr;
    node = Find(root->left, data);
    if (node) return node;
    node = Find(root->right, data);
    return node;
  }

  Node* Find(const T& data) { return Find(GetRoot(), data); }

  void Show(std::ostream& os, const Node* root, int order) const {
    if (!root) return;
    if (order == PreOrder) os << root->data;
    Show(os, root->left, order);
    if (order == InOrder) os << root->data;
    Show(os, root->right, order);
    if (order == PostOrder) os << root->data;
  }

  void DispTree(const BtNode<T>* root) {
    if (!root) return;
    std::cout << root->data;
    if (root->left || root->right) {
      std::cout << "(";
      DispTree(root->left);
      std::cout << ", ";
      DispTree(root->right);
      std::cout << ")";
    }
  }
  void DispTree() {
    DispTree(GetRoot());
    std::cout << "\n";
  }

  friend std::ostream& operator<<(std::ostream& os, const LBTree& t) {
    t.Show(os, t.GetRoot(), PreOrder);
    return os;
  }

  void Delete(Node*& root) {
    if (!root) return;
    Delete(root->left);
    Delete(root->right);
    delete root;
    root = nullptr;
  }

  ~LBTree() { Delete(GetRoot()); };
};
#endif
