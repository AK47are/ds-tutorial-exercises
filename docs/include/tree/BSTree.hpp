#ifndef BSTREE_HPP_
#define BSTREE_HPP_

#include <initializer_list>

#include "LBTree.hpp"
// 不能出现相同关键字，不然查找会紊乱。
template <typename DataType>
class BSTree : public LBTree<DataType> {
  using Node = BtNode<DataType>;

 protected:
  // NOTE: 注意这里返回的是指针的引用，这是为了后面可以修改前指针。
  // 因此不方便使用非递归方法。
  Node*& Find(Node*& root, const DataType& data) {
    if (root == nullptr)
      return root;
    else if (root->data == data)
      return root;
    else if (root->data > data)
      return Find(root->left, data);
    else
      return Find(root->right, data);
  }

  void Insert(Node*& root, const DataType& data) {
    if (root == nullptr)
      root = new Node(data);
    else if (root->data > data)
      Insert(root->left, data);
    else  // 右子树存放大于等于当前结点大小的数。
      Insert(root->right, data);
  }

 public:
  BSTree() = default;
  BSTree(std::initializer_list<DataType> li) {
    for (auto i : li) Insert(i);
  }

  // 使用非递归，因为不需要得到指针的引用。
  Node* Find(const DataType& data) {
    Node* root = this->GetRoot();
    while (root && root->data != data) {
      if (root->data > data)
        root = root->left;
      else if (root->data < data)
        root = root->right;
    }
    return root;
  }
  void Insert(const DataType& data) { Insert(this->GetRoot(), data); }

  void Erase(const DataType& data) {
    Node*& root = Find(this->GetRoot(), data);
    if (!root) return;
    if (!root->left && !root->right) {
      delete root;
      root = nullptr;
    } else if (!root->left || !root->right) {
      auto temp = root;
      root = (root->left) ? root->left : root->right;
      delete temp;
    } else {
      Node*& right = root->left;
      while (right->right) right = right->right;
      Node* temp = right;
      right = temp->left;
      temp->left = root->left;
      temp->right = root->right;
      delete root;
      root = temp;
    }
  }

  ~BSTree() = default;
};

#endif
