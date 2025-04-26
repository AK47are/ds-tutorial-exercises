#include <iostream>

#include "dependency.h"
using namespace std;

LinkNode<char>* Reverse(LinkList<char>& s, LinkNode<char>* cur) {
  if (cur->next == nullptr) {
    s.GetHead()->next = cur;
    return cur;
  }
  Reverse(s, cur->next)->next = cur;
  cur->next = nullptr;
  return cur;
}

int main() {
  LinkList<char> s{'a', 'b', 'c', 'd', 'e', 'f'};
  cout << "原链表：" << s << "\n";
  Reverse(s, s.Begin());
  cout << "逆置后：" << s << "\n";
}
