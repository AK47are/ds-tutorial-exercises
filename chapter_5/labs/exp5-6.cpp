#include <iostream>

#include "../../docs/include/LinkList.hpp"
using namespace std;

LinkNode<char>* GetRNode(LinkNode<char>* cur, int k, int& i) {
  if (cur == nullptr) return nullptr;
  LinkNode<char>* L = GetRNode(cur->next, k, i);
  ++i;
  if (k == i)
    return cur;
  else
    return L;
}

int main() {
  LinkList<char> s{'a', 'b', 'c', 'd', 'e', 'f'};
  cout << "原链表：" << s << "\n";
  int i = 0;
  cout << "得到倒数第几个结点：";
  int k;
  cin >> k;
  cout << "倒数第 " << k << " 个结点为：" << GetRNode(s.Begin(), k, i)->data
       << "\n";
}
