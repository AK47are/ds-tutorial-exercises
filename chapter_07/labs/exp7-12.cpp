#include "dependency.h"

void GetPreSq(BtNode<char>* root, SqString& s) {
  if (!root) {
    s.Push('#');
    return;
  }
  s.Push(root->data);
  GetPreSq(root->left, s);
  GetPreSq(root->right, s);
}

int main() {
  LBTree<char> b1("ABC", "BCA", 3, b1.PreOrder);
  LBTree<char> b2("ABC", "CBA", 3, b2.PreOrder);
  SqString s1, s2;
  GetPreSq(b1.GetRoot(), s1);
  GetPreSq(b2.GetRoot(), s2);
  cout << s1 << "\n";
  cout << s2 << "\n";
  if (s1.Find(s2) != -1)
    cout << "b1 包含 b2\n";
  else
    cout << "b1 不包含 b2\n";
}
