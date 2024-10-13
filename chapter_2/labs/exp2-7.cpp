#include <iostream>

#include "../../docs/include/LinkList.hpp"

template <typename T>
void merge(LinkList<T>& ha, LinkList<T>& hb, LinkList<T>& hc) {
  LinkNode<T>* p1 = ha.GetHead();
  LinkNode<T>* p2 = hb.GetHead();
  LinkNode<T>* p3 = hc.GetHead();
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
  ha.GetHead()->next = ha.End();
  hb.GetHead()->next = hb.End();
  std::cout << hc << "\n";
}
