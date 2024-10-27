#include <iostream>

#include "dependency.h"
using namespace std;

int LeaveCount(BtNode<char>* root) {
  if (!root) return 0;
  int count = LeaveCount(root->left) + LeaveCount(root->right);
  if (!root->left && !root->right) ++count;
  return count;
}

int Width(const LBTree<char>& t) {
  LinkQueue<const BtNode<char>*> q{t.GetRoot()};
  int max_width = 1, now_width = 1, after_width;
  const BtNode<char>* cur;
  while (q.Size() != 0) {
    after_width = 0;
    for (int i = 0; i < now_width; ++i) {
      cur = q.GetFront(), q.DeQueue();
      if (cur->left) q.EnQueue(cur->left), ++after_width;
      if (cur->right) q.EnQueue(cur->right), ++after_width;
    }
    now_width = after_width;
    if (max_width < after_width) max_width = after_width;
  }
  return max_width;
}
int main() {
  LBTree<char> t("ABDEHJKLMNCFGI", "DBJHLKMNEAFCGI", 14,
                 LBTree<char>::PreOrder);
  cout << "结点个数：" << t.Size() << "\n"
       << "叶子结点个数：" << LeaveCount(t.GetRoot()) << "\n"
       << "H 结点值结点的层次：" << t.Depth(t.Find('H')) + 1 << "\n"
       << "树宽度为：" << Width(t) << "\n";
}
