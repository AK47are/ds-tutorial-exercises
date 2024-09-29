#include <iostream>

#include "../../docs/lib/include/LinkList.h"

int main() {
  LinkList<int> l{5, 1, 7, 2, 4, 6, 4, 2};
  std::cout << l << "\n";
  int x = l.Begin()->data;
  auto k = l.Begin();
  std::cout << x << "\n";
  for (auto cur = l.Begin(); cur != l.End(); cur = cur->next)
    if (cur->data < x) {
      int temp = cur->data;
      cur->data = k->data;
      k->data = temp;
      k = k->next;
      std::cout << l << "\tk = " << k->data << '\n';
    }
  std::cout << l << "\n";
}
