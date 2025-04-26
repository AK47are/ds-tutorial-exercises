#include "dependency.h"

char s[50];
int s_size = 0;

void GetPreSq(BtNode<char>* root) {
  if (!root) {
    s[s_size++] = '#';
    return;
  }
  s[s_size++] = root->data;
  GetPreSq(root->left);
  GetPreSq(root->right);
}

// 根据树结点关系 n_0 = n_2 + 1 ，由于n_0 一定为'#', n_2 为字符, 没有 n_1 。
// 遍历前序序列，当符合这个关系时该字符序列为一棵树。
// 当然也可以直接"遍历"构造结点，比这个要简单。
BtNode<char>* CreateTree(char arr[], int size) {
  if (size < 3) return nullptr;
  BtNode<char>* root = new BtNode<char>(arr[0]);
  int index = 0, n0_num = 0, n2_num = 0;  // 左子树与右子树的分界处。
  // cout << arr << " " << size << "\n";
  while (n0_num != n2_num + 1) {
    ++index;
    if (arr[index] == '#')
      ++n0_num;
    else
      ++n2_num;
  }
  root->left = CreateTree(arr + 1, index);
  root->right = CreateTree(arr + index + 1, size - 1 - index);
  return root;
}

int main() {
  LBTree<char> t("ABDEGCFHI", "DBEGACHFI", 9, t.PreOrder);
  t.DispTree();
  GetPreSq(t.GetRoot());
  cout << s << "\n";
  LBTree<char> b;
  b.GetRoot() = CreateTree(s, s_size);
  b.DispTree();
}
