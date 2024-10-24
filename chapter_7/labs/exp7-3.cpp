#include <iostream>

#include "dependency.h"
using namespace std;
using Node = BtNode<char>;

int main() {
  LBTree<char> t1("ABDEHJKLMNCFGI", "DBJHLKMNEAFCGI", 14,
                  LBTree<char>::PreOrder);
  cout << "t1 中序序列：";
  t1.Show(cout, t1.GetRoot(), LBTree<char>::InOrder);
  cout << "\n";
  cout << "t1 后序序列：";
  t1.Show(cout, t1.GetRoot(), LBTree<char>::PostOrder);
  cout << "\n";
  LBTree<char> t2("DJLNMKHEBFIGCA", "DBJHLKMNEAFCGI", 14,
                  LBTree<char>::PostOrder);
  cout << "t2 前序序列：";
  t2.Show(cout, t2.GetRoot(), LBTree<char>::PreOrder);
  cout << "\n";
  cout << "t2 中序序列：";
  t2.Show(cout, t2.GetRoot(), LBTree<char>::InOrder);
  cout << "\n";
}
