#include <iostream>

#include "dependency.h"

void CreateTree(LBTree<char>& t, const SqString& str) {
  if (str.Size() == 0) return;
  t.GetRoot() = new BtNode<char>(str[0]);
  LinkStack<BtNode<char>*> s{t.GetRoot()};
  BtNode<char>* cur = t.GetRoot();
  bool is_right = false;
  for (int i = 1; i < str.Size() - 1; ++i) {
    if (str[i] == '(') {
      is_right = false;
      cur = s.GetTop();
    } else if (str[i] == ',') {
      is_right = true;
    } else if (str[i] == ')') {
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

using namespace std;
int main() {
  LBTree<char> t;
  SqString str{"A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))"};
  CreateTree(t, str);
  t.Show(cout, t.GetRoot(), 0);
  cout << "\n";
  t.Show(cout, t.GetRoot(), 1);
  cout << "\n";
  t.Show(cout, t.GetRoot(), 2);
  cout << "\n";
  cout << "Size: " << t.Size() << "\n";
}
