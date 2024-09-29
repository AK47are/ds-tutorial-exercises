#include <iostream>

#include "../../docs/lib/include/LinkList.h"

template <typename T>
void merge(LinkList<T>& ha, LinkList<T>& hb, LinkList<T>& hc) {
  LinkNode<T>* p1 = ha.PrevNode(-1);
  LinkNode<T>* p2 = hb.PrevNode(-1);
  LinkNode<T>* p3 = hc.PrevNode(-1);
  while (p1->next && p2->next) {
    p3->next = p1->SkipNext();
    p3 = p3->next;
    p3->next = p2->SkipNext();
    p3 = p3->next;
  }
}

int main() {
  LinkList<int> ha{1, 3, 4, 5, 6}, hb{5, 4, 2, 12, 3, 4, 11, 11, 11};
  LinkList<int> hc;
  merge(ha, hb, hc);
  std::cout << hc << "\n";
}
