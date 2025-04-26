#include "dependency.h"

BtNode<int>* CreateBSTree(int arr[], int size) {
  if (size == 0) return nullptr;
  BtNode<int>* root;
  root = new BtNode<int>(arr[size / 2]);
  root->left = CreateBSTree(arr, size / 2);
  root->right = CreateBSTree(arr + size / 2 + 1, (size - 1) / 2);
  return root;
}

int main() {
  int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  BSTree<int> t;
  t.GetRoot() = CreateBSTree(arr, 9);
  t.DispTree();
}
