#include <iostream>

#include "dependency.h"

template <typename T>
struct ThreadBtNode : public TBtNode<T, ThreadBtNode> {
  using BaseNode = TBtNode<T, ThreadBtNode>;
  enum { Nullptr, Node };
  bool left_tag = true;
  bool right_tag = true;

  using BaseNode::BaseNode;
};

void GetInOrder(SqList<ThreadBtNode<char>*, 50>& list,
                ThreadBtNode<char>* root) {
  if (!root) return;
  GetInOrder(list, root->left);
  list.Insert(root, list.Size());
  GetInOrder(list, root->right);
}

void Thread(ThreadBtNode<char>* root) {
  SqList<ThreadBtNode<char>*, 50> list;
  ThreadBtNode<char>* temp;
  GetInOrder(list, root);
  if (list.Size() == 0) return;
  for (int i = 0; i < list.Size(); ++i) {
    temp = list[i];
    if (!temp->left) {
      temp->left_tag = false;
      temp->left = (i != 0) ? list[i - 1] : nullptr;
    }
    if (!temp->right) {
      temp->right_tag = false;
      temp->right = (i != list.Size()) ? list[i + 1] : nullptr;
    }
  }
}

void ThreadTraverse(ThreadBtNode<char>* root) {
  if (root->left_tag != 0) ThreadTraverse(root->left);
  std::cout << root->data;
  if (root->right_tag != 0) ThreadTraverse(root->right);
}

void NonRecursiveThreadTraverse(ThreadBtNode<char>* root) {
  ThreadBtNode<char>* temp = root;
  while (temp->left_tag == temp->Node) temp = temp->left;
  while (temp) {
    std::cout << temp->data;
    if (temp->right_tag == temp->Nullptr) {
      temp = temp->right;
    } else {
      temp = temp->right;
      while (temp->left_tag == temp->Node) temp = temp->left;
    }
  }
}

ThreadBtNode<char>* PreCreate(const char prev_order[], const char in_order[],
                              const int& size) {
  if (size <= 0) return nullptr;
  ThreadBtNode<char>* root = new ThreadBtNode<char>(prev_order[0]);
  int root_index = 0;
  while (in_order[root_index] != prev_order[0]) ++root_index;
  root->left = PreCreate(prev_order + 1, in_order, root_index);
  root->right = PreCreate(prev_order + root_index + 1,
                          in_order + root_index + 1, size - root_index - 1);
  return root;
}

int main() {
  ThreadBtNode<char>* root = PreCreate("ABDEHJKLMNCFGI", "DBJHLKMNEAFCGI", 14);
  Thread(root);
  std::cout << "递归中序遍历：";
  ThreadTraverse(root);
  std::cout << "\n";
  std::cout << "非递归中序遍历：";
  NonRecursiveThreadTraverse(root);
  std::cout << "\n";
}
