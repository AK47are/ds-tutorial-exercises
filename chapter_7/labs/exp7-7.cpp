#include <cmath>
#include <iostream>
#include <map>

#include "dependency.h"
using namespace std;

LinkStack<char> s_max_path;
void PreOrderFindInversePath(LinkStack<char>& s, BtNode<char>* root) {
  if (!root) return;
  s.Push(root->data);
  if (!root->left && !root->right) {
    cout << "到达 " << root->data << " 的逆路径为：" << s << "\n";
    if (s.Size() > s_max_path.Size()) s_max_path = s;
  }
  PreOrderFindInversePath(s, root->left);
  PreOrderFindInversePath(s, root->right);
  s.Pop();
}

// 值得回看
void PostOrderFindInversePath(LBTree<char>& t) {
  LinkStack<BtNode<char>*> s;
  BtNode<char>* cur = t.GetRoot();
  BtNode<char>* prev;
  while (true) {
    while (cur) {
      s.Push(cur);
      cur = cur->left;
    }
    prev = nullptr;
    while (true) {
      cur = s.GetTop();
      // 代表顶点结点的左右子树都已访问。
      // NOTE: 一开始 prev = nullptr
      if (cur->right == prev) {
        if (!s.GetTop()->right && !s.GetTop()->left) {
          cout << "到达 " << cur->data << " 的逆路径为：";
          for (auto i = s.Begin(); i != s.End(); i = i->next)
            cout << i->data->data;
          cout << "\n";
        }
        s.Pop();
        if (s.Size() == 0) return;
        prev = cur;
        cur = s.GetTop();
      } else {
        cur = cur->right;
        break;
      }
    }
  }
}
map<BtNode<char>*, BtNode<char>*> parent;
void GetParent(BtNode<char>* root) {
  if (root->left) {
    parent[root->left] = root;
    GetParent(root->left);
  }
  if (root->right) {
    parent[root->right] = root;
    GetParent(root->right);
  }
}

void LevelOrderFindInversePath(LBTree<char>& t) {
  if (t.Size() == 0) return;
  parent[t.GetRoot()] = nullptr;
  GetParent(t.GetRoot());
  LinkQueue<BtNode<char>*> q{t.GetRoot()};
  BtNode<char>* cur;
  while (q.Size() != 0) {
    cur = q.GetFront();
    q.DeQueue();
    if (cur->left) q.EnQueue(cur->left);
    if (cur->right) q.EnQueue(cur->right);
    if (!cur->left && !cur->right) {
      cout << "到达 " << cur->data << " 的逆路径为：";
      while (cur) {
        cout << cur->data;
        cur = parent[cur];
      }
      cout << "\n";
    }
  }
}

int main() {
  LBTree<char> t("ABDEHJKLMNCFGI", "DBJHLKMNEAFCGI", 14,
                 LBTree<char>::PreOrder);
  LinkStack<char> s;
  cout << "通过先序遍历输出：\n";
  PreOrderFindInversePath(s, t.GetRoot());
  cout << "最长路径为：" << s_max_path << "\n";
  cout << "通过后序遍历输出：\n";
  PostOrderFindInversePath(t);
  cout << "通过层序遍历输出：\n";
  LevelOrderFindInversePath(t);
}
