#include "dependency.h"

bool IsBSTree(BtNode<int>* root) {
  if (!root) return true;
  if ((!root->left || root->data > root->left->data) &&
      (!root->right || root->data < root->right->data) &&
      IsBSTree(root->left) && IsBSTree(root->right))
    return true;
  else
    return false;
}

void RecFind(BtNode<int>* root, const int& data) {
  if (!root) {
    cout << "没有找到！";
    return;
  }
  cout << root->data << " ";
  if (root->data > data)
    return RecFind(root->left, data);
  else if (root->data < data)
    return RecFind(root->right, data);
}

void NonRecFind(BtNode<int>* root, const int& data) {
  while (root && root->data != data) {
    cout << root->data << " ";
    if (root->data > data)
      root = root->left;
    else if (root->data < data)
      root = root->right;
  }
  if (root) cout << root->data << " ";
}

int main() {
  BSTree<int> t{4, 9, 0, 1, 8, 6, 3, 5, 2, 7};
  LBTree<int> b{1, 2, 3, 5, 4};
  cout << "构造二叉搜索树：";
  t.DispTree();
  cout << "测试 IsBSTree()\n";
  cout << "测试树：";
  b.DispTree();
  cout << "结果：" << IsBSTree(b.GetRoot()) << "\n";
  cout << "递归寻找路径：";
  RecFind(t.GetRoot(), 6);
  cout << "\n非递归寻找路径：";
  NonRecFind(t.GetRoot(), 6);
  cout << "\n删除 4, 5 结点：";
  t.Erase(4);
  t.Erase(5);
  t.DispTree();
}
