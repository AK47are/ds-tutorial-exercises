#include "dependency.h"

// Node

// template <typename T>
// class ThreadBTree : public
// void Thread(LinkStack<BtNode<char>*>& stack, BtNode<char>* root) {
//   if (!root) return;
//   if (root->left) stack.Push(root);
//   Thread(stack, root->left);
//   Thread(stack, root->right);
//   if (!root->right) root->right = (stack.Size()) ? stack.Pop()->data :
//   nullptr;
// }

int main() {
  LBTree<char> t{"ABDEHJKLMNCFGI", "DBJHLKMNEAFCGI", 14,
                 LBTree<char>::PreOrder};
}
