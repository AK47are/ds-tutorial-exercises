#include "dependency.h"

BtNode<int>* LCA(BtNode<int>* root, int x, int y) {
  if (!root) return nullptr;
  if (root->data < x && root->data > y)
    return root;
  else if (root->data > x && root->data > y)
    return LCA(root->left, x, y);
  else if (root->data < x && root->data < y)
    return LCA(root->right, x, y);
  else
    return root;
}

int main() {
  BSTree t = {5, 2, 1, 6, 7, 4, 8, 3, 9};
  auto lca = LCA(t.GetRoot(), 1, 4);
  cout << "最近公共祖先是 " << lca->data << "\n";
}
