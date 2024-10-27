#include <cctype>
#include <iostream>

#include "dependency.h"

using namespace std;
void CreateTree(LBTree<char>& t, const SqString& str) {
  if (str.Size() == 0) return;
  t.GetRoot() = new BtNode<char>(str[0]);
  LinkStack<BtNode<char>*> s{t.GetRoot()};
  BtNode<char>* cur = t.GetRoot();
  bool is_right = false;
  for (int i = 1; i < str.Size() - 1; ++i) {
    // cout << "前序遍历：";
    // t.Show(cout, t.GetRoot(), 0);
    // cout << "\n";
    // cout << "中序遍历：";
    // t.Show(cout, t.GetRoot(), 1);
    // cout << "\n";
    if (str[i] == '(') {
      is_right = false;
      cur = s.GetTop();
    } else if (str[i] == ',') {
      is_right = true;
    } else if (str[i] == ')') {
      // cout << "s: " << s.GetTop()->data << "\n";
      s.Pop();
      cur = s.GetTop();
    } else {
      if (is_right == false) {
        cur->left = new BtNode<char>(str[i]);
        if (str[i + 1] == '(') s.Push(cur->left);
      } else {
        cur->right = new BtNode<char>(str[i]);
        if (str[i + 1] == '(') s.Push(cur->right);
      }
    }
  }
}

int main() {
  LBTree<char> t;
  SqString str{"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))"};
  CreateTree(t, str);
  cout << t << "\n";
  cout << "H 结点孩子值：" << t.Find('H')->left->data << " "
       << t.Find('H')->right->data << "\n";
  cout << "高度：" << t.Height() << "\n";
  t.Delete(t.GetRoot());
  cout << t << "\n";
}
